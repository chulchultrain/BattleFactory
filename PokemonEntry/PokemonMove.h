#ifndef __POKEMONMOVE_H_INCLUDED__
#define __POKEMONMOVE_H_INCLUDED__

#include <PokemonEntry/Typing.h>

typedef enum MoveCategory { EMPTY, PHYSICAL, SPECIAL, STATUS} MoveCategory;

typedef struct PokemonMovePrivate PokemonMovePrivate;

/*
void SetName(PokemonMove *this, char *moveName);
void SetDamage(PokemonMove *this, unsigned int D);
void SetType(PokemonMove *this, Type t);
void SetCategory(PokemonMove *this, MoveCategory m);

void GetName(PokemonMove *this, char *dest, unsigned int limit);
Type GetType(PokemonMove *this);
unsigned int GetDamage(PokemonMove *this);
MoveCategory GetCategory(PokemonMove *this);

void ConsolePrint(PokemonMove *this);
*/

typedef struct PokemonMove {

PokemonMovePrivate *mem;

//void (*SetMoveAttributes)(); //sets the attributes of the move(damage,typing, name) using parameters.
//Set Move Name
void (*SetName)();
void (*GetName)();
void (*ConsolePrint)();
void (*SetDamage)();
unsigned int (*GetDamage)();
void (*SetType)();
Type (*GetType)();
void (*SetCategory)();
MoveCategory (*GetCategory)();

} PokemonMove;

PokemonMove *NewPokemonMove();

void ResetPokemonMoveData(PokemonMove *recall);

void DeletePokemonMove(PokemonMove *recall);



#endif
