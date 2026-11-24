#include "JoyBoxWorldBuilder.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

namespace
{
    constexpr float GroundTop = -150.0f;
}

AJoyBoxWorldBuilder::AJoyBoxWorldBuilder()
{
    PrimaryActorTick.bCanEverTick = false;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeAsset.Succeeded())
    {
        CubeMesh = CubeAsset.Object;
    }
}

void AJoyBoxWorldBuilder::BeginPlay()
{
    Super::BeginPlay();
    BuildBlockout();
}

void AJoyBoxWorldBuilder::AddBlock(const FVector& Location, const FVector& Scale)
{
    if (CubeMesh == nullptr)
    {
        return;
    }

    UStaticMeshComponent* Block = NewObject<UStaticMeshComponent>(this);
    Block->SetStaticMesh(CubeMesh);
    Block->SetMobility(EComponentMobility::Movable);
    Block->SetupAttachment(RootComponent);
    Block->SetRelativeLocation(Location);
    Block->SetRelativeScale3D(Scale);
    AddInstanceComponent(Block);
    Block->RegisterComponent();
}

void AJoyBoxWorldBuilder::AddBuilding(float X, float Y, float Width, float Depth, float Height)
{
    const FVector Location(X, Y, GroundTop + (Height * 50.0f));
    AddBlock(Location, FVector(Width, Depth, Height));
}

void AJoyBoxWorldBuilder::BuildBlockout()
{
    // A roughly 1 km square greybox for the first route.
    AddBlock(FVector(0.0f, 0.0f, GroundTop - 50.0f), FVector(500.0f, 500.0f, 1.0f));

    // Main road and raised shoulders, running from the city toward the village.
    AddBlock(FVector(0.0f, 0.0f, GroundTop + 10.0f), FVector(180.0f, 5.0f, 0.2f));
    AddBlock(FVector(0.0f, 620.0f, GroundTop + 20.0f), FVector(180.0f, 1.2f, 0.4f));
    AddBlock(FVector(0.0f, -620.0f, GroundTop + 20.0f), FVector(180.0f, 1.2f, 0.4f));

    // City edge: mid-rise blocks to the west of the road.
    AddBuilding(-12000.0f, 1500.0f, 10.0f, 10.0f, 18.0f);
    AddBuilding(-8500.0f, 1700.0f, 9.0f, 12.0f, 24.0f);
    AddBuilding(-5000.0f, 1500.0f, 12.0f, 10.0f, 15.0f);
    AddBuilding(-12000.0f, -1500.0f, 12.0f, 9.0f, 20.0f);
    AddBuilding(-8500.0f, -1800.0f, 10.0f, 12.0f, 16.0f);
    AddBuilding(-5000.0f, -1500.0f, 9.0f, 9.0f, 22.0f);

    // Village edge: smaller homes with yards to the east.
    AddBuilding(6500.0f, 1600.0f, 8.0f, 7.0f, 3.5f);
    AddBuilding(9500.0f, 1800.0f, 7.0f, 8.0f, 3.0f);
    AddBuilding(12500.0f, 1500.0f, 9.0f, 7.0f, 4.0f);
    AddBuilding(7000.0f, -1700.0f, 8.0f, 8.0f, 3.0f);
    AddBuilding(10000.0f, -1500.0f, 7.0f, 9.0f, 3.5f);
    AddBuilding(13500.0f, -1800.0f, 9.0f, 8.0f, 4.0f);
}
