#ifndef __POKEMONMOVESET_H_INCLUDED__
#define __POKEMONMOVESET_H_INCLUDED__

#include <PokemonEntry/Typing.h>
#include <PokemonEntry/PokemonMove.h>

typedef struct PokemonMoveSetPrivate PokemonMoveSetPrivate;

/*
void SetMoveName(PokemonMoveSet *this, unsigned int choice, char move);

void GetMoveName(PokemonMoveSet *this, unsigned int choice , char *dest, unsigned int limit);

void SetMoveDamage(PokemonMoveSet *this, unsigned int choice, unsigned int damage);

unsigned int GetMoveDamage(PokemonMoveSet *this, unsigned int choice);

void SetMoveType(PokemonMoveSet *this, unsigned int choice,Type t);

Type GetMoveType(PokemonMoveSet *this, unsigned int choice);

void SetMoveCategory(PokemonMoveSet *this, unsigned int choice, MoveCategory m);

MoveCategory GetMoveCategory(PokemonMoveSet *this, unsigned int choice);
*/

typedef struct PokemonMoveSet {
	PokemonMoveSetPrivate *mem;


void (*SetMoveName)();

void (*GetMoveName)();

void (*SetMoveDamage)();

void (*SetMoveType)();

void (*SetMoveCategory)();

void (*ConsolePrint)();

unsigned int (*GetMoveDamage)();

Type (*GetMoveType)();

MoveCategory (*GetMoveCategory)();


} PokemonMoveSet;

PokemonMoveSet *NewPokemonMoveSet();

void DeletePokemonMoveSet(PokemonMoveSet *recall);


#endif
