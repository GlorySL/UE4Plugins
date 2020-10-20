/**
 *	Author:		LiuShuang
 *	Date:		2020.10.19
 */
#pragma once

#include "CoreMinimal.h"
#include "ProtobufHelper.generated.h"
 
/** Helper */
UCLASS(BlueprintType, Blueprintable)
class UProtobufHelper : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	virtual ~UProtobufHelper();

public:
	/** UObject - PropertySetter */
	UFUNCTION(BlueprintCallable, Category = "ProtobufHelper")
	static bool Hello_ProtobufHelper();

};
