// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TBRPGAbilitySystemComponent.generated.h"

class UGameplayAbility;

/**
 * 
 */
UCLASS()
class TBRPG_API UTBRPGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	//Constructor
	UTBRPGAbilitySystemComponent();

	/** Returns a list of currently active ability instances that match the tags */
	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<UGameplayAbility*>& ActiveAbilities);

	/** Version of function in AbilitySystemGlobals that returns correct type */
	static UTBRPGAbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent = false);
	
};
