#ifndef __POKEMONMOVE_H_INCLUDED__
#define __POKEMONMOVE_H_INCLUDED__

#include "Typing.h"
#include "PokemonEffects.h"
typedef struct PokemonMove PokemonMove;

typedef struct PokemonMove {
unsigned int moveID;
unsigned int power;
unsigned int accuracy;
Type type;
EffectContainer *
/**
unsigned int getPower
unsigned int getAccuracy


**/


} PokemonMove;



#endif
