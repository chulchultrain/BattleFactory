#ifndef __POKEMONENTRY_H_INCLUDED__
#define __POKEMONENTRY_H_INCLUDED__

/*problems using extern cuz the const was in a different file so compiler couldnt figure out how much mem to use. couldnt use const because name was getting changed at filescope somehow.
*/




#include <PokemonEntry/Typing.h>
#include <PokemonEntry/PokemonMove.h>

//NOTE MAX OF 21 CHARACTERS IN NAME.
//MAKE A NAME STRUCT/FILE NAH not worth for just a name. 

typedef struct PokemonEntryPrivate PokemonEntryPrivate;
/*
void SetName(PokemonEntry *original, char *name);

void SetLevel(PokemonEntry *original, unsigned int level);

void SetHitPoints(PokemonEntry* original, unsigned int HP);
void SetAttack(PokemonEntry* original, unsigned int A);
void SetDefense(PokemonEntry* original, unsigned int D);
void SetSpecialAttack(PokemonEntry* original, unsigned int SpA);
void SetSpecialDefense(PokemonEntry* original, unsigned int SpD);
void SetSpeed(PokemonEntry* original, unsigned int S);

void SetPrimaryType(PokemonEntry* original, Type primary);
void SetSecondaryType(PokemonEntry* original, Type secondary);

void SetMove(PokemonEntry *original,unsigned int choice, char *move, unsigned int d, Type t, MoveCategory m);

void GetMoveName(PokemonEntry *original, unsigned int choice, char *dest, unsigned int limit);
unsigned int GetMoveDamage(PokemonEntry *obj, unsigned int choice);

Type GetMoveType(PokemonEntry *obj, unsigned int choice);

MoveCategory GetMoveCategory(PokemonEntry *obj, unsigned int choice);

void GetName(PokemonEntry *obj, char* dest, unsigned int limit);

unsigned int GetLevel(PokemonEntry *obj);
unsigned int GetHitPoints(PokemonEntry *obj);
unsigned int GetAttack(PokemonEntry *obj);
unsigned int GetDefense(PokemonEntry *obj);
unsigned int GetSpecialAttack(PokemonEntry *obj);
unsigned int GetSpecialDefense(PokemonEntry *obj);
unsigned int GetSpeed(PokemonEntry *obj);

Type GetPrimaryType(PokemonEntry* obj);

Type GetSecondaryType(PokemonEntry* obj);
*/

typedef struct  PokemonEntry{

PokemonEntryPrivate *mem;

void (*SetName)();

void (*SetLevel)();

void (*SetHitPoints)();
void (*SetAttack)();
void (*SetDefense)();
void (*SetSpecialAttack)();
void (*SetSpecialDefense)();
void (*SetSpeed)();
void (*SetPrimaryType)();
void (*SetSecondaryType)();
void (*SetMove)();

void (*ConsolePrint)();

void (*GetName)();
unsigned int (*GetLevel)();
unsigned int (*GetHitPoints)();
unsigned int (*GetAttack)();
unsigned int (*GetDefense)();
unsigned int (*GetSpecialAttack)();
unsigned int (*GetSpecialDefense)();
unsigned int (*GetSpeed)();
Type (*GetPrimaryType)();
Type (*GetSecondaryType)();
void (*GetMoveName)();;

unsigned int (*GetMoveDamage)();

Type (*GetMoveType)();

MoveCategory (*GetMoveCategory)();


//enum for pokemon Nature

} PokemonEntry;

PokemonEntry *NewPokemonEntry();

//TODO:delete PokemonEntry function
void DeletePokemonEntry(PokemonEntry* recall);




void ResetPokemonEntryData(PokemonEntry* recall);

//void ResetPokemonEntryPointers(PokemonEntry* recall);

void ResetPokemonEntryAll(PokemonEntry* recall);

#endif
