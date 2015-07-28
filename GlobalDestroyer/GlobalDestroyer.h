#ifndef __GLOBALDESTROYER_H_INCLUDED__
#define __GLOBALDESTROYER_H_INCLUDED__


#include <stdio.h>
#include <stdlib.h>

typedef struct PokemonEntry PokemonEntry;
typedef struct Pokedex Pokedex;



void GlobalDestroyer(int mallocFailFlag, PokemonEntry *pokePtr, Pokedex *dexPtr);

#endif
