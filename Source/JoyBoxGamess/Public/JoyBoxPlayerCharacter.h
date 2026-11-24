#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JoyBoxPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class JOYBOXGAMESS_API AJoyBoxPlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AJoyBoxPlayerCharacter();

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void StartJump();
    void StopJump();
    void StartSprint();
    void StopSprint();

    UPROPERTY(VisibleAnywhere, Category="Camera")
    TObjectPtr<USpringArmComponent> CameraBoom;

    UPROPERTY(VisibleAnywhere, Category="Camera")
    TObjectPtr<UCameraComponent> FollowCamera;

    UPROPERTY(EditDefaultsOnly, Category="Movement", meta=(ClampMin="0.0"))
    float WalkSpeed = 400.0f;

    UPROPERTY(EditDefaultsOnly, Category="Movement", meta=(ClampMin="0.0"))
    float SprintSpeed = 700.0f;
};
