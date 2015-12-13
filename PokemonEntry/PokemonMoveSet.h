#ifndef __POKEMONMOVESET_H_INCLUDED__
#define __POKEMONMOVESET_H_INCLUDED__

#include <PokemonEntry/Typing.h>
#include <PokemonEntry/PokemonMove.h>

typedef struct PokemonMoveSetPrivate PokemonMoveSetPrivate;

/*
void SetFirstMoveName(PokemonMoveSet *this, char move);
void SetSecondMoveName(PokemonMoveSet *this, char move);
void SetThirdMoveName(PokemonMoveSet *this, char move);
void SetFourthMoveName(PokemonMoveSet *this, char move);

void GetFirstMoveName(PokemonMoveSet *this, char *dest, unsigned int limit);
void GetSecondMoveName(PokemonMoveSet *this, char *dest, unsigned int limit);
void GetThirdMoveName(PokemonMoveSet *this, char *dest, unsigned int limit);
void GetFourthMoveName(PokemonMoveSet *this, char *dest, unsigned int limit);

void SetFirstMoveDamage(PokemonMoveSet *this, unsigned int damage);
void SetSecondMoveDamage(PokemonMoveSet *this, unsigned int damage);
void SetThirdMoveDamage(PokemonMoveSet *this, unsigned int damage);
void SetFourthMoveDamage(PokemonMoveSet *this, unsigned int damage);

unsigned int GetFirstMoveDamage(PokemonMoveSet *this);
unsigned int GetSecondMoveDamage(PokemonMoveSet *this);
unsigned int GetThirdMoveDamage(PokemonMoveSet *this);
unsigned int GetFourthMoveDamage(PokemonMoveSet *this);

void SetFirstMoveType(PokemonMoveSet *this, Type t);
void SetSecondMoveType(PokemonMoveSet *this, Type t);
void SetThirdMoveType(PokemonMoveSet *this, Type t);
void SetFourthMoveType(PokemonMoveSet *this, Type t);

Type GetFirstMoveType(PokemonMoveSet *this);
Type GetSecondMoveType(PokemonMoveSet *this);
Type GetThirdMoveType(PokemonMoveSet *this);
Type GetFourthMoveType(PokemonMoveSet *this);

void SetFirstMoveCategory(PokemonMoveSet *this, MoveCategory m);
void SetSecondMoveCategory(PokemonMoveSet *this, MoveCategory m);
void SetThirdMoveCategory(PokemonMoveSet *this, MoveCategory m);
void SetFourthMoveCategory(PokemonMoveSet *this, MoveCategory m);

MoveCategory GetFirstMoveCategory(PokemonMoveSet *this);
MoveCategory GetSecondMoveCategory(PokemonMoveSet *this);
MoveCategory GetThirdMoveCategory(PokemonMoveSet *this);
MoveCategory GetFourthMoveCategory(PokemonMoveSet *this);
*/

typedef struct PokemonMoveSet {
	PokemonMoveSetPrivate *mem;


void (*SetFirstMoveName)();
void (*SetSecondMoveName)();
void (*SetThirdMoveName)();
void (*SetFourthMoveName)();

void (*GetFirstMoveName)();
void (*GetSecondMoveName)();
void (*GetThirdMoveName)();
void (*GetFourthMoveName)();

void (*SetFirstMoveDamage)();
void (*SetSecondMoveDamage)();
void (*SetThirdMoveDamage)();
void (*SetFourthMoveDamage)();

void (*SetFirstMoveType)();
void (*SetSecondMoveType)();
void (*SetThirdMoveType)();
void (*SetFourthMoveType)();

void (*SetFirstMoveCategory)();
void (*SetSecondMoveCategory)();
void (*SetThirdMoveCategory)();
void (*SetFourthMoveCategory)();

void (*ConsolePrint)();

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


} PokemonMoveSet;

PokemonMoveSet *NewPokemonMoveSet();

void DeletePokemonMoveSet(PokemonMoveSet *recall);


#endif
