#ifndef __POKEMONENTRY_H_INCLUDED__
#define __POKEMONENTRY_H_INCLUDED__

#include "Typing.h"
#include "PokemonStats.h"

typedef struct  PokemonEntry{

TypeContainer typeData;
char *name;
//weaknesses/resistances/normal list
//moveset

PokemonStats pokeStats;

//enum for pokemon Nature

} PokemonEntry;

#endif
