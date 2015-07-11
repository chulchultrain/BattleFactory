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

typedef struct PokemonEntryPrivate PokemonEntryPrivate;

typedef struct  PokemonEntry{

PokemonEntryPrivate *mem;

void (*SetName)();

void (*SetHitPoints)();
void (*SetAttack)();
void (*SetDefense)();
void (*SetSpecialAttack)();
void (*SetSpecialDefense)();
void (*SetSpeed)();
void (*SetPrimaryType)();
void (*SetSecondaryType)();

void (*ConsolePrint)();

//enum for pokemon Nature

} PokemonEntry;

PokemonEntry *NewPokemonEntry();
PokemonEntry *FullPokemonEntry(char* name, PokemonStats *statsHolder, TypeContainer *typeHolder);

//TODO:delete PokemonEntry function
void DeletePokemonEntry(PokemonEntry* recall);

void SetPokemonName(PokemonEntry* original, const char* name);

void SetPokemonEntryFunctionPointers(PokemonEntry* original);

void SetEntryHP(PokemonEntry* original, const int* HP);

void ResetPokemonEntryData(PokemonEntry* recall);

void ResetPokemonEntryPointers(PokemonEntry* recall);

void ResetPokemonEntryAll(PokemonEntry* recall);

void SetEntryHP(PokemonEntry* original, const int* HP);
void SetEntryA(PokemonEntry* original, const int* A);
void SetEntryD(PokemonEntry* original, const int* D);
void SetEntrySpA(PokemonEntry* original, const int* SpA);
void SetEntrySpD(PokemonEntry* original, const int* SpD);
void SetEntryS(PokemonEntry* original, const int* S);

void SetEntryPrimaryType(PokemonEntry* original, const Type* primary);
void SetEntrySecondaryType(PokemonEntry* original, const Type* secondary);

void PokemonEntryConsolePrint(PokemonEntry* obj);

#endif
