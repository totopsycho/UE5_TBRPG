// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "TBRPGAbilitySystemComponent.h"
#include "AttributeSetBase.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class TBRPG_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;



	/** Character Health Attribute */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Health);
	

	/** Max Health. Used as a workaround for the Min/Max values not being available in the base implementation of the attribute table */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxHealth);

	/** Character Dexterity, used to calculate initiative and ranged attacks */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Dexterity)
	UFUNCTION(Category = "Attributes Functions")
	FGameplayAttribute DexterityAttribute();

	/** Strenght Attribute for melee attack*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Strength)
	UFUNCTION(Category = "Attributes Functions")
	FGameplayAttribute StrengthAttribute();

	/** Character Constitution, used mainly to calculate health value */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData Constitution;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Constitution)
	UFUNCTION(Category = "Attributes Functions")
	FGameplayAttribute ConstitutionAttribute();

	/** Character Wisdom, mainly for cleric spell */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData Wisdom;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Wisdom)
	UFUNCTION(Category = "Attributes Functions")
	FGameplayAttribute WisdomAttribute();


	/** Intelligence Attribute mainly for spell*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Intelligence)
	UFUNCTION(Category = "Attributes Functions")
	FGameplayAttribute IntelligenceAttribute();

	/** Character Charisma, used mainly for npc interaction */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData Charisma;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Charisma)
	UFUNCTION(Category = "Attributes Functions")
	FGameplayAttribute CharismaAttribute();

	/** Armor Class */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData AC;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, AC)
	UFUNCTION(Category = "Attributes Functions")
	FGameplayAttribute ACAttribute();

	/** Experience granted when an enemy die */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	FGameplayAttributeData Exp;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Exp)
	UFUNCTION(Category = "Attributes Functions")
	FGameplayAttribute ExpAttribute();

};