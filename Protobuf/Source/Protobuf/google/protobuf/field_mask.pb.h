// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/field_mask.proto

#ifndef PROTOBUF_INCLUDED_google_2fprotobuf_2ffield_5fmask_2eproto
#define PROTOBUF_INCLUDED_google_2fprotobuf_2ffield_5fmask_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_google_2fprotobuf_2ffield_5fmask_2eproto PROTOBUF_API

namespace protobuf_google_2fprotobuf_2ffield_5fmask_2eproto {
// Internal implementation detail -- do not use these members.
struct PROTOBUF_API TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void PROTOBUF_API AddDescriptors();
}  // namespace protobuf_google_2fprotobuf_2ffield_5fmask_2eproto
namespace google {
namespace protobuf {
class FieldMask;
class FieldMaskDefaultTypeInternal;
PROTOBUF_API extern FieldMaskDefaultTypeInternal _FieldMask_default_instance_;
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {
template<> PROTOBUF_API ::google::protobuf::FieldMask* Arena::CreateMaybeMessage<::google::protobuf::FieldMask>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {

// ===================================================================

class PROTOBUF_API FieldMask : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.FieldMask) */ {
 public:
  FieldMask();
  virtual ~FieldMask();

  FieldMask(const FieldMask& from);

  inline FieldMask& operator=(const FieldMask& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FieldMask(FieldMask&& from) noexcept
    : FieldMask() {
    *this = ::std::move(from);
  }

  inline FieldMask& operator=(FieldMask&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const FieldMask& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FieldMask* internal_default_instance() {
    return reinterpret_cast<const FieldMask*>(
               &_FieldMask_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(FieldMask* other);
  friend void swap(FieldMask& a, FieldMask& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FieldMask* New() const final {
    return CreateMaybeMessage<FieldMask>(NULL);
  }

  FieldMask* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<FieldMask>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const FieldMask& from);
  void MergeFrom(const FieldMask& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FieldMask* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated string paths = 1;
  int paths_size() const;
  void clear_paths();
  static const int kPathsFieldNumber = 1;
  const ::std::string& paths(int index) const;
  ::std::string* mutable_paths(int index);
  void set_paths(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_paths(int index, ::std::string&& value);
  #endif
  void set_paths(int index, const char* value);
  void set_paths(int index, const char* value, size_t size);
  ::std::string* add_paths();
  void add_paths(const ::std::string& value);
  #if LANG_CXX11
  void add_paths(::std::string&& value);
  #endif
  void add_paths(const char* value);
  void add_paths(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& paths() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_paths();

  // @@protoc_insertion_point(class_scope:google.protobuf.FieldMask)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::std::string> paths_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_google_2fprotobuf_2ffield_5fmask_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FieldMask

// repeated string paths = 1;
inline int FieldMask::paths_size() const {
  return paths_.size();
}
inline void FieldMask::clear_paths() {
  paths_.Clear();
}
inline const ::std::string& FieldMask::paths(int index) const {
  // @@protoc_insertion_point(field_get:google.protobuf.FieldMask.paths)
  return paths_.Get(index);
}
inline ::std::string* FieldMask::mutable_paths(int index) {
  // @@protoc_insertion_point(field_mutable:google.protobuf.FieldMask.paths)
  return paths_.Mutable(index);
}
inline void FieldMask::set_paths(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:google.protobuf.FieldMask.paths)
  paths_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void FieldMask::set_paths(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:google.protobuf.FieldMask.paths)
  paths_.Mutable(index)->assign(std::move(value));
}
#endif
inline void FieldMask::set_paths(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  paths_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:google.protobuf.FieldMask.paths)
}
inline void FieldMask::set_paths(int index, const char* value, size_t size) {
  paths_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.FieldMask.paths)
}
inline ::std::string* FieldMask::add_paths() {
  // @@protoc_insertion_point(field_add_mutable:google.protobuf.FieldMask.paths)
  return paths_.Add();
}
inline void FieldMask::add_paths(const ::std::string& value) {
  paths_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:google.protobuf.FieldMask.paths)
}
#if LANG_CXX11
inline void FieldMask::add_paths(::std::string&& value) {
  paths_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:google.protobuf.FieldMask.paths)
}
#endif
inline void FieldMask::add_paths(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  paths_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:google.protobuf.FieldMask.paths)
}
inline void FieldMask::add_paths(const char* value, size_t size) {
  paths_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:google.protobuf.FieldMask.paths)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
FieldMask::paths() const {
  // @@protoc_insertion_point(field_list:google.protobuf.FieldMask.paths)
  return paths_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
FieldMask::mutable_paths() {
  // @@protoc_insertion_point(field_mutable_list:google.protobuf.FieldMask.paths)
  return &paths_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_google_2fprotobuf_2ffield_5fmask_2eproto
