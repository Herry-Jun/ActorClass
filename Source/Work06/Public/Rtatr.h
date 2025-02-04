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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rtatr|Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mvatr|Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mvatr|Properties", meta = (AllowPrivateAccess = "true"))
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FTimerHandle TimerHandle_HideActor;
	FTimerHandle TimerHandle_ShowActor;

	void HideActor();
	void ShowActor();

};
