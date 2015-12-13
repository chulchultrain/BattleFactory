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
void SetHitPoints(PokemonEntry* original, unsigned int HP);
void SetAttack(PokemonEntry* original, unsigned int A);
void SetDefense(PokemonEntry* original, unsigned int D);
void SetSpecialAttack(PokemonEntry* original, unsigned int SpA);
void SetSpecialDefense(PokemonEntry* original, unsigned int SpD);
void SetSpeed(PokemonEntry* original, unsigned int S);

void SetPrimaryType(PokemonEntry* original, Type primary);
void SetSecondaryType(PokemonEntry* original, Type secondary);

void SetFirstMove(PokemonEntry *original, char *move, unsigned int d, Type t, MoveCategory m);
void SetSecondMove(PokemonEntry *original, char *move, unsigned int d, Type t, MoveCategory m);
void SetThirdMove(PokemonEntry *original, char *move, unsigned int d, Type t, MoveCategory m);
void SetFourthMove(PokemonEntry *original, char *move, unsigned int d, Type t, MoveCategory m);

void GetFirstMoveName(PokemonEntry *original, char *dest, unsigned int limit);
void GetSecondMoveName(PokemonEntry *original, char *dest, unsigned int limit);
void GetThirdMoveName(PokemonEntry *original, char *dest, unsigned int limit);
void GetFourthMoveName(PokemonEntry *original, char *dest, unsigned int limit);

unsigned int GetFirstMoveDamage(PokemonEntry *obj);
unsigned int GetSecondMoveDamage(PokemonEntry *obj);
unsigned int GetThirdMoveDamage(PokemonEntry *obj);
unsigned int GetFourthMoveDamage(PokemonEntry *obj);

Type GetFirstMoveType(PokemonEntry *obj);
Type GetSecondMoveType(PokemonEntry *obj);
Type GetThirdMoveType(PokemonEntry *obj);
Type GetFourthMoveType(PokemonEntry *obj);

MoveCategory GetFirstMoveCategory(PokemonEntry *obj);
MoveCategory GetSecondMoveCategory(PokemonEntry *obj);
MoveCategory GetThirdMoveCategory(PokemonEntry *obj);
MoveCategory GetFourthMoveCategory(PokemonEntry *obj);

void GetEntryName(PokemonEntry *obj, char* dest, unsigned int limit);

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

void (*SetHitPoints)();
void (*SetAttack)();
void (*SetDefense)();
void (*SetSpecialAttack)();
void (*SetSpecialDefense)();
void (*SetSpeed)();
void (*SetPrimaryType)();
void (*SetSecondaryType)();
void (*SetFirstMove)();
void (*SetSecondMove)();
void (*SetThirdMove)();
void (*SetFourthMove)();

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
void (*GetFirstMoveName)();
void (*GetSecondMoveName)();
void (*GetThirdMoveName)();
void (*GetFourthMoveName)();

unsigned int (*GetFirstMoveDamage)();
unsigned int (*GetSecondMoveDamage)();
unsigned int (*GetThirdMoveDamage)();
unsigned int (*GetFourthMoveDamage)();

Type (*GetFirstMoveType)();
Type (*GetSecondMoveType)();
Type (*GetThirdMoveType)();
Type (*GetFourthMoveType)();

MoveCategory (*GetFirstMoveCategory)();
MoveCategory (*GetSecondMoveCategory)();
MoveCategory (*GetThirdMoveCategory)();
MoveCategory (*GetFourthMoveCategory)();

//enum for pokemon Nature

} PokemonEntry;

PokemonEntry *NewPokemonEntry();

//TODO:delete PokemonEntry function
void DeletePokemonEntry(PokemonEntry* recall);




void ResetPokemonEntryData(PokemonEntry* recall);

//void ResetPokemonEntryPointers(PokemonEntry* recall);

void ResetPokemonEntryAll(PokemonEntry* recall);

#endif
