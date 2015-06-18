#include "PokemonEntry.h"
#include <stdlib.h>

//max size of name will be 20 characters, I don't think such a length exists.
//provide protection if longer than twenty characters is entered.


PokemonEntry *NewPokemonEntry() {
	PokemonEntry *result = malloc(sizeof(PokemonEntry));
	result->name[0] = '\0';
	result->typeData = NewTypeContainer();
	result->pokeStats = NewPokemonStats();
	return result;

}


