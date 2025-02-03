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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mvatr|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mvatr|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mvatr|Properties")
	float MoveSpeed;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mvatr|Properties")
	float RotationSpeed;
	float MoveRange;
	FVector StartLocation;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
