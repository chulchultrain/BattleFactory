#ifndef __POKEMON_ENTRY_C_INCLUDED__
#define __POKEMON_ENTRY_C_INCLUDED__

#include "PokemonEntry.h"
#include <stdlib.h>


//TODO:NO MAGIC NUMBERS PLZ
//provide protection if longer than MAXNAME characters is entered.
//checked before this function If longer then end will be truncated.
void copyName(char* source, char* dest) {
	int i = 0;
	while(i < MAX_NAME && source[i] != 0) {
		dest[i] = source[i];
		i++;
	}
	if(i == MAX_NAME)	
		dest[MAX_NAME - 1] = 0;
}
PokemonEntry *NewPokemonEntry() {
	PokemonEntry *result = malloc(sizeof(PokemonEntry));
	result->name[0] = 0;
	result->typeData = NewTypeContainer();
	result->pokeStats = NewPokemonStats();
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
	return result;


}

void DeletePokemonEntry(PokemonEntry* recall){
	DeletePokemonStats(recall->pokeStats);
	DeleteTypeContainer(recall->typeData);
	free(recall);
}

#endif









