# UE4 - Plugins - Protobuf

* UE4 plugins
A protobuf source integration for UE4.

* Link
参考链接
https://github.com/jashking/UE4Protobuf ^.^ Thanks (libprotobuf 3.5.1)

* 当前版本
UnrealEngine 4.24.3
protobuf 3.6.1 (protobuf-cpp-3.6.1.zip)
https://github.com/protocolbuffers/protobuf/releases/tag/v3.6.1


## 测试平台 ##

* 已测试通过
	* `Win32`, `Win64`
	* `Android`
	* `MAC`
	* `iOS`
	* `Linux`

## 如何使用 ##

* 将 `Protobuf` 文件夹复制到自己的项目的`Plugins`目录下
* 修改自己项目的 `.build.cs` 文件，在 `PublicDependencyModuleNames` 中增加 `Protobuf` 模块，并增加 `ShadowVariableWarningLevel = WarningLevel.Off; bEnableUndefinedIdentifierWarnings = false;`，禁掉警告

## 以下记录完整步骤 ##

### 提取 libprotobuf 源码 ###

* 到 [protobuf releases](https://github.com/google/protobuf/releases)下载 `protobuf-cpp` 源码包
* 用 `CMake` 生成 `Visual Studio` 工程

``` bash
cd /D protobuf-3.2.0\cmake

cmake.exe -G "Visual Studio 14 2015 Win64" .

or

use cmake-gui

```

* 将工程 `libprotobuf` 中用到的源码文件和对应的头文件提取出来

### 修改 libprotobuf 源码 ###

主要是去掉两个宏开关 `GOOGLE_PROTOBUF_NO_RTTI` 和 `HAVE_PTHREAD`

#### 去掉 HAVE_PTHREAD 宏 ####

在非 `Windows` 平台下都要打开 `HAVE_PTHREAD` 宏

打开 `google/protobuf/stubs/common.cc`，把两个地方的 `elif defined(HAVE_PTHREAD)` 改成 `#else`

并且把第一处以下两行代码删除

``` cpp
#else
#error "No suitable threading library available."
```

#### 去掉 GOOGLE_PROTOBUF_NO_RTTI 宏 ####

在所有平台下都要禁用 `RTTI`，因为 `UE4` 禁用了 `C++` 的运行时类型识别(`typeid` 和 `dynamic_cast`)

打开 `google/protobuf/arena.h`，将

``` cpp
#ifndef GOOGLE_PROTOBUF_NO_RTTI
#define RTTI_TYPE_ID(type) (&typeid(type))
#else
#define RTTI_TYPE_ID(type) (NULL)
#endif
```

改为

``` cpp
#define RTTI_TYPE_ID(type) (NULL)
```

打开 `google/protobuf/generated_message_reflection.h`，将

``` cpp
function: DynamicCastToGenerated

#ifdef GOOGLE_PROTOBUF_NO_RTTI
  bool ok = &T::default_instance() ==
            from->GetReflection()->GetMessageFactory()->GetPrototype(
                from->GetDescriptor());
  return ok ? down_cast<T*>(from) : NULL;
#else
  return dynamic_cast<T*>(from);
#endif
```

改为

``` cpp
//#ifdef GOOGLE_PROTOBUF_NO_RTTI
#if true             // By L.S
  bool ok = &T::default_instance() ==
            from->GetReflection()->GetMessageFactory()->GetPrototype(
                from->GetDescriptor());
  return ok ? down_cast<T*>(from) : NULL;
#else
  return dynamic_cast<T*>(from);
#endif
```

将

``` cpp
function: dynamic_cast_if_available

#ifdef GOOGLE_PROTOBUF_NO_RTTI
  // Avoid the compiler warning about unused variables.
  (void)from;
  return NULL;
#else
  return dynamic_cast<To>(from);
#endif
```

改为

``` cpp
//#ifdef GOOGLE_PROTOBUF_NO_RTTI
#if true             // By L.S
  // Avoid the compiler warning about unused variables.
  (void)from;
  return NULL;
#else
  return dynamic_cast<To>(from);
#endif
```

打开 `google/protobuf/stubs/casts.h`，删除以下两处代码

``` cpp
#if !defined(NDEBUG) && !defined(GOOGLE_PROTOBUF_NO_RTTI)
  assert(f == NULL || dynamic_cast<To>(f) != NULL);  // RTTI: debug mode only!
#endif
```

和

``` cpp
#if !defined(NDEBUG) && !defined(GOOGLE_PROTOBUF_NO_RTTI)
  // RTTI: debug mode only!
  assert(dynamic_cast<ToAsPointer>(&f) != NULL);
#endif
```

### 替换 LIBPROTOBUF_EXPORT 宏 ###

将代码里除 `google/protobuf/stubs/port.h` 中的 `LIBPROTOBUF_EXPORT` 宏替换为 `PROTOBUF_API`

将代码里的两处 `#elif defined(PROTOBUF_USE_DLLS)` 替换为 `#elif defined(PROTOBUF_API)`

### 禁用编译警告 ###

因为 `UE4` 会将一些编译警告当成错误，所以要将编译过程中 `libprotobuf` 中的警告禁用掉

在 `Protobuf` 模块的编译描述文件 `Protobuf.build.cs` 中增加

``` cpp
ShadowVariableWarningLevel = WarningLevel.Off;
bEnableUndefinedIdentifierWarnings = false;
```

在 `google/protobuf/map_field.h` 文件开头增加 

``` cpp
#ifdef _MSC_VER
#pragma warning(disable: 4661)
#endif //_MSC_VER

其他地方也有很多禁用警告处理

```

### `noexcept` 关键字问题 ###

`Protobuf` 从 `3.5` 版本开始，逐渐使用 `C++11` 语法，其中就使用了 `noexcept` 关键字，但是在虚幻中默认是不使用异常处理的，这样就会导致编译失败，错误为

```bash
error C4577: 在未指定异常处理模式的情况下使用了 "noexcept"；不一定会在异常时终止。指定 /EHsc
```

有以下几种改法

* 第一种是在 `build.cs` 中打开 `bEnableExceptions` 开关，本文中就是使用了这个方法
* 第二种是将 `noexcept` 关键字删掉，不过这样也需要修改 `protoc` 的源码，保证生成出来的 `.pb.h/.pb.cc` 中也没有 `noexcept`
* 第三种是修改 `UBT` 源码，加入 `/EHsc` 标记，这种不推荐

