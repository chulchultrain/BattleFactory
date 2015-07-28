#include "GlobalDestroyer.h"

#include "PokemonEntry.h"
#include "Pokedex.h"



void GlobalDestroyer(int mallocFailFlag, PokemonEntry *pokePtr, Pokedex *dexPtr) {
	static PokemonEntry *pokemonEntryPtr;
	static Pokedex *pokedexPtr;
	if(mallocFailFlag != 0) {
		if(pokemonEntryPtr != 0) {
			DeletePokemonEntry(pokemonEntryPtr);
			pokemonEntryPtr = 0;
					}
		if(pokedexPtr != 0) {
			DestroyPokedex(pokedexPtr);
			pokedexPtr = 0;
					}
		exit(0); //TODO:SHOULD IT BE 1 OR 0?
	}
	else {
		if(pokePtr != 0)
			pokemonEntryPtr = pokePtr;
		if(dexPtr != 0)
			pokedexPtr = dexPtr;

	}
	

}
