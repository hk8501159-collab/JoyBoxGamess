#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JoyBoxWorldBuilder.generated.h"

class USceneComponent;
class UStaticMesh;

UCLASS()
class JOYBOXGAMESS_API AJoyBoxWorldBuilder : public AActor
{
    GENERATED_BODY()

public:
    AJoyBoxWorldBuilder();

protected:
    virtual void BeginPlay() override;

private:
    void AddBlock(const FVector& Location, const FVector& Scale);
    void AddBuilding(float X, float Y, float Width, float Depth, float Height);
    void BuildBlockout();

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<USceneComponent> SceneRoot;

    UPROPERTY()
    TObjectPtr<UStaticMesh> CubeMesh;
};
