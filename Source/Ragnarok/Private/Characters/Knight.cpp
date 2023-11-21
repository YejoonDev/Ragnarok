// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Knight.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AKnight::AKnight()
{
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	SpringArmComponent->TargetArmLength = 800.f;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetSprite()->SetRelativeScale3D(FVector(5.f, 0.f, 5.f));

	GetCharacterMovement()->GravityScale = 0.f;
}
