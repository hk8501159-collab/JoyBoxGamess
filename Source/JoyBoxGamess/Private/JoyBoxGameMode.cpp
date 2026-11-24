#include "JoyBoxGameMode.h"

#include "JoyBoxPlayerCharacter.h"
#include "JoyBoxWorldBuilder.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerStart.h"

AJoyBoxGameMode::AJoyBoxGameMode()
{
    DefaultPawnClass = AJoyBoxPlayerCharacter::StaticClass();
    PlayerControllerClass = APlayerController::StaticClass();
}

void AJoyBoxGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);

    if (UWorld* World = GetWorld())
    {
        World->SpawnActor<APlayerStart>(
            APlayerStart::StaticClass(),
            FTransform(FRotator::ZeroRotator, FVector(0.0f, 0.0f, 0.0f)));
        World->SpawnActor<AJoyBoxWorldBuilder>(AJoyBoxWorldBuilder::StaticClass());
    }
}
