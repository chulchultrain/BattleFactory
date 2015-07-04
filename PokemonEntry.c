#ifndef __POKEMON_ENTRY_C_INCLUDED__
#define __POKEMON_ENTRY_C_INCLUDED__

#include "PokemonEntry.h"
#include <stdlib.h>


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
	result->name[0] = 0;
	result->typeData = NewTypeContainer();
	result->pokeStats = NewPokemonStats();

	SetPokemonEntryFunctionPointers(result);
	return result;

}

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
	copyName(name, result->name);
	result->typeData = CopyTypeContainer(typeHolder); //TODO:CopyConstructor
	result->pokeStats = CopyPokemonStats(statsHolder); //TODO:CopyConstructor
	SetPokemonEntryFunctionPointers(result);
	return result;


}

void DeletePokemonEntry(PokemonEntry* recall){
	//zero out name before free
	DeletePokemonStats(recall->pokeStats);
	DeleteTypeContainer(recall->typeData);
	free(recall);
}

void SetPokemonName(PokemonEntry* original, const char* name) {
	int i;
	for(i = 0; i < MAX_NAME; i++)
		if(name[i] == 0)
			break;
	if(i == MAX_NAME)
		return; //TODO:assert
	
	copyName(name, original->name);
}

void SetPokemonEntryFunctionPointers(PokemonEntry* original) {
	original->SetName = SetPokemonName;
}

#endif









