#ifndef __POKEMONMOVESET_H_INCLUDED__
#define __POKEMONMOVESET_H_INCLUDED__

#include <PokemonEntry/Typing.h>
#include <PokemonEntry/PokemonMove.h>

typedef struct PokemonMoveSetPrivate PokemonMoveSetPrivate;


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
