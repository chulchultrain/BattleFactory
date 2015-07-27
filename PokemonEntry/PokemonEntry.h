#ifndef __POKEMONENTRY_H_INCLUDED__
#define __POKEMONENTRY_H_INCLUDED__

/*problems using extern cuz the const was in a different file so compiler couldnt figure out how much mem to use. couldnt use const because name was getting changed at filescope somehow.
*/

#ifndef MAX_NAME
#define MAX_NAME 21
#endif




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

void (*GetName)();
unsigned int (*GetHitPoints)();
unsigned int (*GetAttack)();
unsigned int (*GetDefense)();
unsigned int (*GetSpecialAttack)();
unsigned int (*GetSpecialDefense)();
unsigned int (*GetSpeed)();
unsigned int (*GetPrimaryType)();
unsigned int (*GetSecondaryType)();

//enum for pokemon Nature

} PokemonEntry;

PokemonEntry *NewPokemonEntry();

//TODO:delete PokemonEntry function
void DeletePokemonEntry(PokemonEntry* recall);




void ResetPokemonEntryData(PokemonEntry* recall);

//void ResetPokemonEntryPointers(PokemonEntry* recall);

void ResetPokemonEntryAll(PokemonEntry* recall);

#endif
