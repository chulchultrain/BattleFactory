#ifndef __GLOBALDESTROYER_H_INCLUDED__
#define __GLOBALDESTROYER_H_INCLUDED__




typedef struct PokemonEntry PokemonEntry;
typedef struct Pokedex Pokedex;



void GlobalDestroyer(int mallocFailFlag, PokemonEntry *pokePtr, Pokedex *dexPtr);

#endif
