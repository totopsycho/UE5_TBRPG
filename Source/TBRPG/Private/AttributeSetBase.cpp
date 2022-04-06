// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	//Clamping Health based on Max Health.
	/*if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}*/
}


FGameplayAttribute UAttributeSetBase::DexterityAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Dexterity));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UAttributeSetBase::StrengthAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Strength));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UAttributeSetBase::ConstitutionAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Constitution));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UAttributeSetBase::WisdomAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Wisdom));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UAttributeSetBase::ACAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, AC));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UAttributeSetBase::ExpAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Exp));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UAttributeSetBase::IntelligenceAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Intelligence));
	return FGameplayAttribute(Property);
}

FGameplayAttribute UAttributeSetBase::CharismaAttribute()
{
	static UProperty* Property = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Charisma));
	return FGameplayAttribute(Property);
}
