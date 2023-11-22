// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Knight.h"
#include "Inputs/InputConfigData.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperFlipbookComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameManagers/MyPlayerController.h"

AKnight::AKnight()
{
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	SpringArmComponent->TargetArmLength = 800.f;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetSprite()->SetRelativeScale3D(FVector(5.f, 0.f, 5.f));

	GetSprite()->SetEnableGravity(false);
	GetCapsuleComponent()->SetEnableGravity(false);
	GetCharacterMovement()->GravityScale = 0.f;
	
	GetCharacterMovement()->DefaultLandMovementMode = MOVE_Flying;
	GetCharacterMovement()->BrakingDecelerationFlying = 100000.f;
	GetCharacterMovement()->MaxAcceleration = 100000.f;
	
}

void AKnight::BeginPlay()
{
	Super::BeginPlay();

	const AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	Subsystem->AddMappingContext(InputMappingContext, 0);
	
}

void AKnight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(InputConfigData->MoveAction,
		ETriggerEvent::Triggered, this, &AKnight::Move);
}

void AKnight::Move(const FInputActionValue& InValue)
{
	const FVector3d MovementVector = InValue.Get<FVector3d>();
	
	AddMovementInput(GetActorForwardVector(), MovementVector.X);
	AddMovementInput(GetActorUpVector(), MovementVector.Z);
}
