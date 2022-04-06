// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "AttributeSetBase.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UTBRPGAbilitySystemComponent>(TEXT("AbilitySystemComp"));

	AttributeSetBaseComp = CreateDefaultSubobject <UAttributeSetBase>(TEXT("AttributeStatBaseComp"));

}



// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();


	if (IsValid(AbilitySystemComponent))

	{
		//GetGameplayAttributeValueChangedDelegate will enable you to bind delegates without programming them manually.
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBaseComp->GetHealthAttribute()).AddUObject(this, &ABaseCharacter::OnHealthChangedInternal);

		AttributeSetBaseComp=AbilitySystemComponent->GetSet<UAttributeSetBase>();

		
	}
	
}


void ABaseCharacter::OnHealthChangedInternal(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}


float ABaseCharacter::GetHealth() const
{
	if (IsValid(AttributeSetBaseComp))
	{
		return AttributeSetBaseComp->GetHealth();
	}

	return -1.0f;
}

float ABaseCharacter::GetMaxHealth() const
{
	if (IsValid(AttributeSetBaseComp))
	{
		return AttributeSetBaseComp->GetMaxHealth();
	}

	return 0.0f;
}


// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire)
{
	if (AbilitySystemComponent)
	{
		if (HasAuthority() && AbilityToAquire)
		{
			FGameplayAbilitySpecDef SpecDef = FGameplayAbilitySpecDef();
			SpecDef.Ability = AbilityToAquire;
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(SpecDef, 1);
			AbilitySystemComponent->GiveAbility(AbilitySpec);
		}
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

bool ABaseCharacter::ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation)
{
	if (AbilitySystemComponent)
	{
		return AbilitySystemComponent->TryActivateAbilitiesByTag(AbilityTags, bAllowRemoteActivation);
	}

	return false;
}

void ABaseCharacter::GetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<UGameplayAbility*>& ActiveAbilities)
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->GetActiveAbilitiesWithTags(AbilityTags, ActiveAbilities);
	}
}

void ABaseCharacter::RemoveAbilityWithTags(FGameplayTagContainer AbilityTags)
{
	TArray<FGameplayAbilitySpec*> MatchingAbilities;
	AbilitySystemComponent->GetActivatableGameplayAbilitySpecsByAllMatchingTags(AbilityTags, MatchingAbilities, true);
	for (FGameplayAbilitySpec* Spec : MatchingAbilities)
	{
		AbilitySystemComponent->ClearAbility(Spec->Handle);
	}
}


