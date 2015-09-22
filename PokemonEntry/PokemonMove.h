#ifndef __POKEMONMOVE_H_INCLUDED__
#define __POKEMONMOVE_H_INCLUDED__

#include <PokemonEntry/Typing.h>

typedef struct PokemonMovePrivate PokemonMovePrivate;


typedef struct PokemonMove {

PokemonMovePrivate *mem;

void (*SetMoveAttributes)(); //sets the attributes of the move(damage,typing, name) using parameters.
//Set Move Name
void (*SetName)();
void (*GetName)();
void (*ConsolePrint)();
void (*SetDamage)();
unsigned int (*GetDamage)();
void (*SetType)();
Type (*GetType)();

} PokemonMove;

PokemonMove *NewPokemonMove();

void ResetPokemonMoveData(PokemonMove *recall);

void DeletePokemonMove(PokemonMove *recall);



#endif
