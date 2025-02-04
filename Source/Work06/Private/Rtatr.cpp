#include "Rtatr.h"
#include "TimerManager.h"

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

	RotationSpeed = 50.0f;

}

void ARtatr::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(3000.0f, -3000.0f, 3000.0f));
	SetActorRotation(FRotator(45.0f, 0.0f, 0.0f));
	SetActorScale3D(FVector(10.0f));

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_HideActor, this, &ARtatr::HideActor, 5.0f, false);

}

void ARtatr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void ARtatr::HideActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	FVector NewLocation = FVector(
		FMath::RandRange(-5000.0f, 5000.0f),
		FMath::RandRange(-5000.0f, 5000.0f),
		FMath::RandRange(500.0f, 3000.0f)
	);
	SetActorLocation(NewLocation);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShowActor, this, &ARtatr::ShowActor, 1.0f, false);
}

void ARtatr::ShowActor()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_HideActor, this, &ARtatr::HideActor, 5.0, false);

}