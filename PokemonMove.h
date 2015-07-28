/**
23 July 2015 - Creation. Only name and type useful info for battle factory predictor right now. Not trying to recode the entire pokemon framework. 
This is for use in a simple hash table. Don't need indirection through function pointers. 


**/



#ifndef __POKEMONMOVE_H_INCLUDED__
#define __POKEMONMOVE_H_INCLUDED__

#include "Typing.h"
#include "PokemonEffects.h"

#ifndef MAX_MOVE_NAME
#define MAX_MOVE_NAME 15

typedef enum MoveType {PHYSICAL, SPECIAL, STATUS} MoveType;

typedef struct PokemonMove PokemonMove;



typedef struct PokemonMove {
unsigned int moveID;
char name[MAX_MOVE_NAME];
Type type;
/**
unsigned int power;

EffectContainer *effects;
unsigned int accuracy;
**/


/**
unsigned int getPower
unsigned int getAccuracy


**/


} PokemonMove;



#endif
