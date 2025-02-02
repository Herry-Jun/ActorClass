#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mvatr.generated.h"

UCLASS()
class WORK06_API AMvatr : public AActor
{
	GENERATED_BODY()
	
public:	

	AMvatr();

protected:

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float MoveSpeed;
	float RotationSpeed;
	float MoveRange;
	FVector StartLocation;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
