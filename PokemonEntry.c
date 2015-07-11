#ifndef __POKEMON_ENTRY_C_INCLUDED__
#define __POKEMON_ENTRY_C_INCLUDED__

#include "PokemonEntry.h"
#include <stdlib.h>
#include <stdio.h>

struct PokemonEntryPrivate {

TypeContainer *typeData;

char name[MAX_NAME];
//weaknesses/resistances/normal list
//moveset

PokemonStats *pokeStats;

};

void SetPokemonName(PokemonEntry* original, const char* name);


void SetEntryHP(PokemonEntry* original, const int* HP);



void SetEntryHP(PokemonEntry* original, const int* HP);
void SetEntryA(PokemonEntry* original, const int* A);
void SetEntryD(PokemonEntry* original, const int* D);
void SetEntrySpA(PokemonEntry* original, const int* SpA);
void SetEntrySpD(PokemonEntry* original, const int* SpD);
void SetEntryS(PokemonEntry* original, const int* S);

void SetEntryPrimaryType(PokemonEntry* original, const Type* primary);
void SetEntrySecondaryType(PokemonEntry* original, const Type* secondary);

void PokemonEntryConsolePrint(PokemonEntry* obj);


//TODO:NO MAGIC NUMBERS PLZ
//provide protection if longer than MAXNAME characters is entered.
//checked before this function If longer then end will be truncated.
void copyName(const char* source, char* dest) {
	int i = 0;
	while(i < MAX_NAME && source[i] != 0) {
		dest[i] = source[i];
		i++;
	}
	if(i == MAX_NAME) //took up all the space so must truncate for'\0'
		dest[MAX_NAME - 1] = 0;
	else
		dest[i] = 0; //append '\0'
}
PokemonEntry *NewPokemonEntry() {
	PokemonEntry *result = malloc(sizeof(PokemonEntry));
	result->mem = malloc(sizeof(PokemonEntryPrivate));

	result->mem->name[0] = 0;
	result->mem->typeData = NewTypeContainer();
	result->mem->pokeStats = NewPokemonStats();

	SetPokemonEntryFunctionPointers(result);
	return result;

}

//TODO:POKEMONENTRY COPY CONSTRUCTOR

/*If we're gonna make a full pokemon stats, might as well make full new pokemon
  entry. Will include stats, type and name
*/
PokemonEntry *FullPokemonEntry(char* name, PokemonStats* statsHolder, TypeContainer* typeHolder) {
	int i;
	for(i = 0; i < MAX_NAME; i++)
		if(name[i] == 0)
			break;
	if(i == MAX_NAME)
		return NULL; //TODO:assert. name > 20c should have already checked
	PokemonEntry *result = malloc(sizeof(PokemonEntry));
	result->mem = malloc(sizeof(PokemonEntryPrivate));
	copyName(name, result->mem->name);
	result->mem->typeData = CopyTypeContainer(typeHolder); //TODO:CopyConstructor
	result->mem->pokeStats = CopyPokemonStats(statsHolder); //TODO:CopyConstructor
	SetPokemonEntryFunctionPointers(result);
	return result;


}

void ResetPokemonEntryData(PokemonEntry* recall) {
	//TODO:ADD CLEAR NAME
	int i;
	for(i = 0; i < MAX_NAME; i++)
		recall->mem->name[i] = 0;


	ResetPokemonStatsData(recall->mem->pokeStats);
	ResetTypeContainerData(recall->mem->typeData);
}

void ResetPokemonEntryPointers(PokemonEntry* recall) {
	recall->SetName = NULL;
	recall->SetHitPoints = NULL;
	recall->SetAttack = NULL;
	recall->SetDefense = NULL;
	recall->SetSpecialAttack = NULL;
	recall->SetSpecialDefense = NULL;
	recall->SetSpeed = NULL;
	recall->SetPrimaryType = NULL;
	recall->SetSecondaryType = NULL;
	ResetPokemonStatsPointers(recall->mem->pokeStats);
	ResetTypeContainerPointers(recall->mem->typeData);
}

void ResetPokemonEntryAll(PokemonEntry* recall) {
	ResetPokemonEntryData(recall);
	ResetPokemonEntryPointers(recall);
}

void DeletePokemonEntry(PokemonEntry* recall){
	//zero out name before free
	ResetPokemonEntryAll(recall);
	DeletePokemonStats(recall->mem->pokeStats);
	DeleteTypeContainer(recall->mem->typeData);
	free(recall->mem);
	free(recall);
}

void SetPokemonName(PokemonEntry* original, const char* name) {
	int i;
	for(i = 0; i < MAX_NAME; i++)
		if(name[i] == 0)
			break;
	if(i == MAX_NAME)
		return; //TODO:assert
	
	copyName(name, original->mem->name);
}



void SetPokemonEntryFunctionPointers(PokemonEntry* original) {
	original->SetName = SetPokemonName;
	original->SetHitPoints = SetEntryHP;
	original->SetAttack = SetEntryA;
	original->SetDefense = SetEntryD;
	original->SetSpecialAttack = SetEntrySpA;
	original->SetSpecialDefense = SetEntrySpD;
	original->SetSpeed = SetEntryS;
	original->SetPrimaryType = SetEntryPrimaryType;
	original->SetSecondaryType = SetEntrySecondaryType;
	original->ConsolePrint = PokemonEntryConsolePrint;

}

void SetEntryHP(PokemonEntry* original, const int* HP) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetHP(statsPtr, HP);
	
//	SetHitPoints(original->pokeStats, HP);
}

void SetEntryA(PokemonEntry* original, const int* A) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetA(statsPtr, A);
//	SetAttack(original->pokeStats, A);
}

void SetEntryD(PokemonEntry* original, const int* D) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetD(statsPtr, D);
//	SetDefense(original->pokeStats, D);
}

void SetEntrySpA(PokemonEntry* original, const int* SpA) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetSpA(statsPtr, SpA);
//	SetSpecialAttack(original->pokeStats, SpA);
}

void SetEntrySpD(PokemonEntry* original, const int* SpD) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetSpD(statsPtr, SpD);
//	SetSpecialDefense(original->pokeStats, SpD);
}

void SetEntryS(PokemonEntry* original, const int* S) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetS(statsPtr, S);
//	SetSpeed(original->pokeStats, S);
}

void SetEntryPrimaryType(PokemonEntry* original, const Type* primary) {
	TypeContainer *typePtr = original->mem->typeData;
	typePtr->SetPrimary(typePtr, primary);
//	SetPrimaryType(original->typeData, primary);
}

void SetEntrySecondaryType(PokemonEntry* original, const Type* secondary) {
	TypeContainer *typePtr = original->mem->typeData;
	typePtr->SetSecondary(typePtr, secondary);
//	SetSecondaryType(original->typeData, secondary);
}

void PokemonEntryConsolePrint(PokemonEntry* obj) {

	
	printf("Name is %s\n", obj->mem->name);	

	PokemonStats *statsPtr = obj->mem->pokeStats;
	TypeContainer *typePtr = obj->mem->typeData;
	
	statsPtr->ConsolePrint(statsPtr);
	typePtr->ConsolePrint(typePtr);

//	PokemonStatsConsolePrint(obj->pokeStats);
//	TypeContainerConsolePrint(obj->typeData);
}
#endif









