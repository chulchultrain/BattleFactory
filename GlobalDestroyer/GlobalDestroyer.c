#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdio.h>
#include <stdlib.h>
#include <PokemonEntry/PokemonEntry.h>
#include <Pokedex/Pokedex.h>

//only one pokedex and one pokemonEntry maximum will be active at one time


void GlobalDestroyer(int mallocFailFlag, PokemonEntry *pokePtr, Pokedex *dexPtr) {
	static PokemonEntry *pokemonEntryPtr;
	static Pokedex *pokedexPtr;
	if(mallocFailFlag != 0) {
		printf("FAILED COMPLETELY\n");
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
