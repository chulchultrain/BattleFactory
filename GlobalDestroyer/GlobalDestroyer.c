#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdio.h>
#include <stdlib.h>
#include <PokemonEntry/PokemonEntry.h>
#include <Pokedex/Pokedex.h>
#include <SpecialConstants/SpecialConstants.h>

//only one pokedex and one pokemonEntry maximum will be active at one time

//i dont make public because the only thing that should use this is the global destroyer.



/*

void GlobalDestroyer(int mallocFailFlag, void *deletePtr, ALLTYPES type) {
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

*/


void GlobalDestroyer(int mallocFailFlag, void *deletePtr, ALLTYPES type) {
	static PokemonEntry *pokemonEntryMem[MAX_POKEMONENTRY_IN_MEM] = {0};
	static Pokedex *pokedexMem[MAX_POKEDEX_IN_MEM] = {0};
	//static BattleSim *battleSimMem[MAX_BATTLESIM_IN_MEM];

	static unsigned int pokemonEntryCounter;
	static unsigned int pokedexCounter;
	//static unsigned int battleSimCounter;

	if(mallocFailFlag == 1) {
		unsigned int i;
		for(i = 0; i < pokemonEntryCounter; i++)
			if( pokemonEntryMem[i] != 0)
				DeletePokemonEntry(pokemonEntryMem[i]);
		for(i = 0; i < pokedexCounter; i++)
			if( pokedexMem[i] != 0)
				DeletePokedex(pokedexMem[i]);
/**
		for(i = 0; i < battleSimCounter && battleSimMem[i] != 0; i++)
			DeleteBattleSim(battleSimMem[i]);


**/
	}
	else if(mallocFailFlag == 2) { //only kill off one item. used for clever multilayer delete and if delete used outside of global destroy
		unsigned int i;
		switch(type) {
			case NOTHING:
						printf("NOTHING AT switch in Global Destroyer\n");
						GlobalDestroyer(1,0,0);
						break;
			case POKEDEX:
						
						for(i = 0; i < MAX_POKEDEX_IN_MEM && pokedexMem[i] != 0; i++)
							if(pokedexMem[i] == deletePtr)
								break;
						DeletePokedex( (Pokedex *) deletePtr);
						pokedexMem[i] = 0;
						//TODO:add so that move array entries to fill the empty slot, then decrement counter
			case POKEMONENTRY:
						for(i = 0; i < MAX_POKEMONENTRY_IN_MEM && pokemonEntryMem[i] != 0; i++)
							if(pokemonEntryMem[i] == deletePtr)
								break;
						DeletePokemonEntry( (PokemonEntry *) deletePtr);
						pokemonEntryMem[i] = 0;

		} 
		
	}
	else { //new entry added to array of pointers, to be deleted later

		switch(type) {
			case NOTHING:		printf("NOTHING AT switch in Global Destroyer\n");
						GlobalDestroyer(1,0,0);
						break;

			case POKEDEX:		if( pokedexCounter == MAX_POKEDEX_IN_MEM) {
							DeletePokedex( (Pokedex *) deletePtr);
							GlobalDestroyer(1,0,0); }
				 		pokedexMem[pokedexCounter] = (Pokedex *)deletePtr;
				     		pokedexCounter += 1;
				    		break;

			case POKEMONENTRY: 	if( pokemonEntryCounter == MAX_POKEMONENTRY_IN_MEM) {
							DeletePokemonEntry( (PokemonEntry *)deletePtr);
							GlobalDestroyer(1,0,0); }							
						pokemonEntryMem[pokemonEntryCounter] = (PokemonEntry *)deletePtr;
					   	pokemonEntryCounter += 1;
					  	break;
/**
			case BATTLESIMULATION:	if ( battleSimCounter == MAX_BATTLESIM_IN_MEM) {
							DeleteBattleS
										}
						battleSimMem[battleSimCounter] = (BattleSimMem *)deletePtr;
						battleSimCounter += 1;
						break;
**/
		}

	}
	
}
