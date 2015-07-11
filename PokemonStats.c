#include "PokemonStats.h"
#include <stdlib.h>
#include <stdio.h>

struct PokemonStatsPrivate {

int HitPoints;
int Attack;
int Defense;
int SpecialAttack;
int SpecialDefense;
int Speed;

};

void SetHitPoints(PokemonStats* original, const int* HitPoints);

void SetAttack(PokemonStats* original, const int* Attack);

void SetDefense(PokemonStats* original, const int* Defense);

void SetSpecialAttack(PokemonStats* original, const int* SpecialAttack);

void SetSpecialDefense(PokemonStats* original, const int* SpecialDefense);

void SetSpeed(PokemonStats* original, const int* Speed);

void SetPokemonStatsFunctionPointers(PokemonStats* original);

void PokemonStatsConsolePrint(PokemonStats* obj);

PokemonStats* NewPokemonStats() {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	pokeStats->mem = malloc(sizeof(PokemonStatsPrivate));
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
	pokeStats->mem = malloc(sizeof(PokemonStatsPrivate));
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
PokemonStats* FullNewPokemonStats(const int* HP,const int* A,const int* D,const int* SpA, const int* SpD, const int* S) {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	pokeStats->mem = malloc(sizeof(PokemonStatsPrivate));
	pokeStats->mem->HitPoints = *HP;
	pokeStats->mem->Attack = *A;
	pokeStats->mem->Defense = *D;
	pokeStats->mem->SpecialAttack = *SpA;
	pokeStats->mem->SpecialDefense = *SpD;
	pokeStats->mem->Speed = *S;

	SetPokemonStatsFunctionPointers(pokeStats);

	return pokeStats;	


}

void ResetPokemonStatsData(PokemonStats* recall) {
	recall->mem->HitPoints = 0;
	recall->mem->Attack = 0;
	recall->mem->Defense = 0;
	recall->mem->SpecialAttack = 0;
	recall->mem->SpecialDefense = 0;
	recall->mem->Speed = 0;
}

void ResetPokemonStatsPointers(PokemonStats* recall) {
	recall->SetHP = 0;
	recall->SetA = 0;
	recall->SetD = 0;
	recall->SetSpA = 0;
	recall->SetSpD = 0;
	recall->SetS = 0;
}

void ResetPokemonStatsAll(PokemonStats* recall) {
	ResetPokemonStatsData(recall);
	ResetPokemonStatsPointers(recall);
}

void DeletePokemonStats(PokemonStats* recall){
	//TODO:zero values before free
	ResetPokemonStatsAll(recall);
	free(recall->mem);
	free(recall);
}

void SetHitPoints(PokemonStats* original, const int* HitPoints) {
	original->mem->HitPoints = *HitPoints;
}

void SetAttack(PokemonStats* original, const int* Attack) {
	original->mem->Attack = *Attack;
}

void SetDefense(PokemonStats* original, const int* Defense) {
	original->mem->Defense = *Defense;
}

void SetSpecialAttack(PokemonStats* original, const int* SpecialAttack) {
	original->mem->SpecialAttack = *SpecialAttack;
}

void SetSpecialDefense(PokemonStats* original, const int* SpecialDefense) {
	original->mem->SpecialDefense = *SpecialDefense;
}

void SetSpeed(PokemonStats* original, const int* Speed) {
	original->mem->Speed = *Speed;
}


void SetPokemonStatsFunctionPointers(PokemonStats* original) {


	original->SetHP = SetHitPoints;
	original->SetA = SetAttack;
	original->SetD = SetDefense;
	original->SetSpA = SetSpecialAttack;
	original->SetSpD = SetSpecialDefense;
	original->SetS = SetSpeed;
	original->ConsolePrint = PokemonStatsConsolePrint;

}

void PokemonStatsConsolePrint(PokemonStats* obj) {
	printf("HP is %d\n", obj->mem->HitPoints);
	printf("Attack is %d\n", obj->mem->Attack);
	printf("Defense is %d\n", obj->mem->Defense);
	printf("Special Attack is %d\n", obj->mem->SpecialAttack);
	printf("Special Defense is %d\n", obj->mem->SpecialDefense);
	printf("Speed is %d\n", obj->mem->Speed);
}



