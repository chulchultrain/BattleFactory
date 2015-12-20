#include <PokemonEntry/PokemonStats.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdlib.h>
#include <stdio.h>

struct PokemonStatsPrivate {
unsigned int Level;
unsigned int HitPoints;
unsigned int Attack;
unsigned int Defense;
unsigned int SpecialAttack;
unsigned int SpecialDefense;
unsigned int Speed;

};
void SetLevel(PokemonStats* original, unsigned int level); 
void SetHitPoints(PokemonStats* original, unsigned int HitPoints);

void SetAttack(PokemonStats* original, unsigned int Attack);

void SetDefense(PokemonStats* original, unsigned int Defense);

void SetSpecialAttack(PokemonStats* original, unsigned int SpecialAttack);

void SetSpecialDefense(PokemonStats* original, unsigned int SpecialDefense);

void SetSpeed(PokemonStats* original, unsigned int Speed);

unsigned int GetLevel(PokemonStats* obj);
unsigned int GetHitPoints(PokemonStats* obj);
unsigned int GetAttack(PokemonStats* obj);
unsigned int GetDefense(PokemonStats* obj);
unsigned int GetSpecialAttack(PokemonStats* obj);
unsigned int GetSpecialDefense(PokemonStats* obj);
unsigned int GetSpeed(PokemonStats* obj);

void SetPokemonStatsFunctionPointers(PokemonStats* original);

void PokemonStatsConsolePrint(PokemonStats* obj);

PokemonStats* NewPokemonStats() {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	if (pokeStats == 0)
		GlobalDestroyer(1,0,0);
	pokeStats->mem = malloc(sizeof(PokemonStatsPrivate));
	if (pokeStats->mem == 0) {
		GlobalDestroyer(1,0,0);
		}
	pokeStats->mem->Level = 0;
	pokeStats->mem->HitPoints = 0;
	pokeStats->mem->Attack = 0;
	pokeStats->mem->Defense = 0;
	pokeStats->mem->SpecialAttack = 0;
	pokeStats->mem->SpecialDefense = 0;
	pokeStats->mem->Speed = 0;

	SetPokemonStatsFunctionPointers(pokeStats);

	return pokeStats;

}

//TODO:TEST copy constructor
PokemonStats* CopyPokemonStats(PokemonStats* original) {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	if (pokeStats == 0)
		GlobalDestroyer(1,0,0);
	pokeStats->mem = malloc(sizeof(PokemonStatsPrivate));
	if (pokeStats->mem == 0) {
		GlobalDestroyer(1,0,0);
		}
	pokeStats->mem->HitPoints = original->mem->HitPoints;
	pokeStats->mem->Attack = original->mem->Attack;
	pokeStats->mem->Defense = original->mem->Defense;
	pokeStats->mem->SpecialAttack = original->mem->SpecialAttack;
	pokeStats->mem->SpecialDefense = original->mem->SpecialDefense;
	pokeStats->mem->Speed = original->mem->Speed;

	SetPokemonStatsFunctionPointers(pokeStats);

	return pokeStats;
}


//Currently no default parameters wtf c doesnt have function overloading
//read that should pass constant pointers instead of by value to avoid creating new 
//objects. Although primitives arent nearly as costly.
PokemonStats* FullNewPokemonStats(unsigned int HP,unsigned int A,unsigned int D,unsigned int SpA, unsigned int SpD, unsigned int S) {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	if (pokeStats == 0)
		GlobalDestroyer(1,0,0);
	pokeStats->mem = malloc(sizeof(PokemonStatsPrivate));
	if (pokeStats->mem == 0) {
		GlobalDestroyer(1,0,0);
		}
	pokeStats->mem->HitPoints = HP;
	pokeStats->mem->Attack = A;
	pokeStats->mem->Defense = D;
	pokeStats->mem->SpecialAttack = SpA;
	pokeStats->mem->SpecialDefense = SpD;
	pokeStats->mem->Speed = S;

	SetPokemonStatsFunctionPointers(pokeStats);

	return pokeStats;	


}

void ResetPokemonStatsData(PokemonStats* recall) {
	if(recall != 0) {
		if(recall->mem != 0) {
			recall->mem->Level = 0;
			recall->mem->HitPoints = 0;
			recall->mem->Attack = 0;
			recall->mem->Defense = 0;
			recall->mem->SpecialAttack = 0;
			recall->mem->SpecialDefense = 0;
			recall->mem->Speed = 0; }
		}
}
/**
void ResetPokemonStatsPointers(PokemonStats* recall) {
	recall->SetHP = 0;
	recall->SetA = 0;
	recall->SetD = 0;
	recall->SetSpA = 0;
	recall->SetSpD = 0;
	recall->SetS = 0;
	recall->ConsolePrint = 0;	
	recall->GetHP = 0;
	recall->GetA = 0;
	recall->GetD = 0;
	recall->GetSpA = 0;
	recall->GetSpD = 0;
	recall->GetS = 0;
}
**/
void ResetPokemonStatsAll(PokemonStats* recall) {
	ResetPokemonStatsData(recall);
//	ResetPokemonStatsPointers(recall);
}

void DeletePokemonStats(PokemonStats* recall){
	if( recall != 0) {
		if(recall->mem != 0); {
			ResetPokemonStatsData(recall);
			free(recall->mem);
			recall->mem = 0;
				}
		free(recall);
	}
}

void SetLevel(PokemonStats* original, unsigned int level) {
	original->mem->Level = level;
}

void SetHitPoints(PokemonStats* original, unsigned int HitPoints) {
	original->mem->HitPoints = HitPoints;
}

void SetAttack(PokemonStats* original, unsigned int Attack) {
	original->mem->Attack = Attack;
}

void SetDefense(PokemonStats* original, unsigned int Defense) {
	original->mem->Defense = Defense;
}

void SetSpecialAttack(PokemonStats* original, unsigned int SpecialAttack) {
	original->mem->SpecialAttack = SpecialAttack;
}

void SetSpecialDefense(PokemonStats* original, unsigned int SpecialDefense) {
	original->mem->SpecialDefense = SpecialDefense;
}

void SetSpeed(PokemonStats* original, unsigned int Speed) {
	original->mem->Speed = Speed;
}


void SetPokemonStatsFunctionPointers(PokemonStats* original) {

	original->SetL = SetLevel;
	original->SetHP = SetHitPoints;
	original->SetA = SetAttack;
	original->SetD = SetDefense;
	original->SetSpA = SetSpecialAttack;
	original->SetSpD = SetSpecialDefense;
	original->SetS = SetSpeed;
	original->ConsolePrint = PokemonStatsConsolePrint;
	original->GetL = GetLevel;
	original->GetHP = GetHitPoints;
	original->GetA = GetAttack;
	original->GetD = GetDefense;
	original->GetSpA = GetSpecialAttack;
	original->GetSpD = GetSpecialDefense;
	original->GetS = GetSpeed;

}

unsigned int GetLevel(PokemonStats* obj) {
	return obj->mem->Level;
}

unsigned int GetHitPoints(PokemonStats* obj) {
	return obj->mem->HitPoints;
}

unsigned int GetAttack(PokemonStats* obj) {
	return obj->mem->Attack;
}

unsigned int GetDefense(PokemonStats* obj) {
	return obj->mem->Defense;
}
unsigned int GetSpecialAttack(PokemonStats* obj) {
	return obj->mem->SpecialAttack;
}
unsigned int GetSpecialDefense(PokemonStats* obj) {
	return obj->mem->SpecialDefense;
}
unsigned int GetSpeed(PokemonStats* obj) {
	return obj->mem->Speed;
}

void PokemonStatsConsolePrint(PokemonStats* obj) {
	printf("Level is %u\n",obj->mem->Level);
	printf("HP is %u\n", obj->mem->HitPoints);
	printf("Attack is %u\n", obj->mem->Attack);
	printf("Defense is %u\n", obj->mem->Defense);
	printf("Special Attack is %u\n", obj->mem->SpecialAttack);
	printf("Special Defense is %u\n", obj->mem->SpecialDefense);
	printf("Speed is %u\n", obj->mem->Speed);
}





