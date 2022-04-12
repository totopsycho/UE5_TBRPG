// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TBRPGAbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UAttributeSetBase;




UCLASS()
class TBRPG_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterBase")
	UTBRPGAbilitySystemComponent* AbilitySystemComponent;

	UTBRPGAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	const UAttributeSetBase* AttributeSetBaseComp;

	//Function to bind to Attribute Changed delegate. Calls On Health Changed.
	void OnHealthChangedInternal(const FOnAttributeChangeData& Data);

	//Blueprint-implementable On Health Changed event. Used to send information to the UI about current health.
	UFUNCTION(BlueprintImplementableEvent, Category = "Abilities|Attributes")
	void OnHealthChanged(float oldValue, float newValue);

	/** Blueprint-accessible getter for the current health value. */
	UFUNCTION(BlueprintPure, Category = "Abilities|Attributes")
	float GetHealth() const;

	/** Blueprint-accessible getter for the max health value. */
	UFUNCTION(BlueprintPure, Category = "Abilities|Attributes")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation = true);

	/** Returns a list of active abilities matching the specified tags. This only returns if the ability is currently running */
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void GetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<UGameplayAbility*>& ActiveAbilities);


	//Remove Abilities with Tag
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void RemoveAbilityWithTags(FGameplayTagContainer AbilityTags);

	/** Returns the character level that is passed to the ability system */
	UFUNCTION(BlueprintCallable)
	virtual int32 GetCharacterLevel() const;

	/** Modifies the character level, this may change abilities. Returns true on success */
	UFUNCTION(BlueprintCallable)
	virtual bool SetCharacterLevel(int32 NewLevel);

protected:

	/** The level of this character, should not be modified directly once it has already spawned */
	UPROPERTY(EditAnywhere, Category = Abilities)
	int32 CharacterLevel;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	/** Function To grant ability to the character */
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
