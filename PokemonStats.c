#include "PokemonStats.h"
#include <stdlib.h>
#include <stdio.h>

PokemonStats* NewPokemonStats() {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	pokeStats->HitPoints = 0;
	pokeStats->Attack = 0;
	pokeStats->Defense = 0;
	pokeStats->SpecialAttack = 0;
	pokeStats->SpecialDefense = 0;
	pokeStats->Speed = 0;

	return pokeStats;

}

//copy constructor
PokemonStats* CopyPokemonStats(PokemonStats* original) {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	pokeStats->HitPoints = original->HitPoints;
	pokeStats->Attack = original->Attack;
	pokeStats->Defense = original->Defense;
	pokeStats->SpecialAttack = original->SpecialAttack;
	pokeStats->SpecialDefense = original->SpecialDefense;
	pokeStats->Speed = original->Speed;

	return pokeStats;
}


//Currently no default parameters wtf c doesnt have function overloading
//read that should pass constant pointers instead of by value to avoid creating new 
//objects. Although primitives arent nearly as costly.
PokemonStats* FullNewPokemonStats(const int* HP,const int* A,const int* D,const int* SpA, const int* SpD, const int* S) {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	pokeStats->HitPoints = *HP;
	pokeStats->Attack = *A;
	pokeStats->Defense = *D;
	pokeStats->SpecialAttack = *SpA;
	pokeStats->SpecialDefense = *SpD;
	pokeStats->Speed = *S;

	return pokeStats;	


}

void DeletePokemonStats(PokemonStats* recall){
	
	free(recall);
}

void SetHitPoints(PokemonStats* original, const int* HitPoints) {
	original->HitPoints = *HitPoints;
}

void SetAttack(PokemonStats* original, const int* Attack) {
	original->Attack = *Attack;
}

void SetDefense(PokemonStats* original, const int* Defense) {
	original->Defense = *Defense;
}

void SetSpecialAttack(PokemonStats* original, const int* SpecialAttack) {
	original->SpecialAttack = *SpecialAttack;
}

void SetSpecialDefense(PokemonStats* original, const int* SpecialDefense) {
	original->SpecialDefense = *SpecialDefense;
}

void SetSpeed(PokemonStats* original, const int* Speed) {
	original->Speed = *Speed;
}

