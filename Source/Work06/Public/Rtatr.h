#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rtatr.generated.h"

UCLASS()
class WORK06_API ARtatr : public AActor
{
	GENERATED_BODY()
	
public:	
	ARtatr();

protected:

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
