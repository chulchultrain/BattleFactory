#ifndef __POKEMONENTRY_H_INCLUDED__
#define __POKEMONENTRY_H_INCLUDED__

#include "Typing.h"
#include "PokemonStats.h"

//NOTE MAX OF 21 CHARACTERS IN NAME.
//MAKE A NAME STRUCT/FILE NAH not worth for just a name. 
typedef struct  PokemonEntry{

TypeContainer *typeData;
char name[21];
//weaknesses/resistances/normal list
//moveset

PokemonStats *pokeStats;

//enum for pokemon Nature

} PokemonEntry;

PokemonEntry *NewPokemonEntry();

#endif
