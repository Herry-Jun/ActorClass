#include "Rtatr.h"

ARtatr::ARtatr()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//Script/Engine.StaticMesh'/Game/Resources/Props/MaterialSphere.MaterialSphere'
	//Script/Engine.Material'/Game/Resources/Materials/M_Concrete_Grime.M_Concrete_Grime'

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/MaterialSphere.MaterialSphere"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Concrete_Grime.M_Concrete_Grime"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 100.0f;

}

void ARtatr::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.0f, 0.0f, 70.0f));
	SetActorScale3D(FVector(1.5f));

}

void ARtatr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Pitch += RotationSpeed * DeltaTime;
		SetActorRotation(NewRotation);

	}
}


