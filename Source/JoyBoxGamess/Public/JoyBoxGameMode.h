#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JoyBoxGameMode.generated.h"

UCLASS()
class JOYBOXGAMESS_API AJoyBoxGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AJoyBoxGameMode();

protected:
    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
