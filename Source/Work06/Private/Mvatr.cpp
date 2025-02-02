#include "Mvatr.h"

AMvatr::AMvatr()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Steel.M_Metal_Steel"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 150.0f;
	MoveSpeed = 300.0f;
	MoveRange = 1000.0f;
	StartLocation = FVector::ZeroVector;

}


void AMvatr::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1.5f));
	StartLocation = GetActorLocation();

}

void AMvatr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		FVector NewLocation = GetActorLocation() + FVector(0.0f, MoveSpeed * DeltaTime, 0.0f);
		float DistanceMoved = FVector::Dist(StartLocation, NewLocation);

		if (DistanceMoved >= MoveRange)
		{
			MoveSpeed = -MoveSpeed;
		}
		else
		{
			SetActorLocation(NewLocation);
		}

	}

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}