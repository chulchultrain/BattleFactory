#ifndef __POKEMONENTRY_H_INCLUDED__
#define __POKEMONENTRY_H_INCLUDED__

/*problems using extern cuz the const was in a different file so compiler couldnt figure out how much mem to use. couldnt use const because name was getting changed at filescope somehow.
*/

#ifndef MAX_NAME
#define MAX_NAME 21
#endif

#include "Typing.h"
#include "PokemonStats.h"


//NOTE MAX OF 21 CHARACTERS IN NAME.
//MAKE A NAME STRUCT/FILE NAH not worth for just a name. 
typedef struct  PokemonEntry{

TypeContainer *typeData;
char name[MAX_NAME];
//weaknesses/resistances/normal list
//moveset

PokemonStats *pokeStats;

void (*SetName)();

void (*SetHP)();

//enum for pokemon Nature

} PokemonEntry;

PokemonEntry *NewPokemonEntry();
PokemonEntry *FullPokemonEntry(char* name, PokemonStats *statsHolder, TypeContainer *typeHolder);

//TODO:delete PokemonEntry function
void DeletePokemonEntry(PokemonEntry* recall);

void SetPokemonName(PokemonEntry* original, const char* name);

void SetPokemonEntryFunctionPointers(PokemonEntry* original);

void SetEntryHP(PokemonEntry* original, const int* HP);

#endif
