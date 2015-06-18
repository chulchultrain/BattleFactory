#ifndef __TYPING_H_INCLUDED__
#define __TYPING_H_INCLUDED__

typedef enum Type { NONE, NORMAL, GRASS, BUG, FIRE, WATER, LIGHTNING, FLYING, ROCK, GROUND, POISON, PSYCHIC, DARK, STEEL, DRAGON }Type;

typedef struct TypeContainer{

Type primary;
Type secondary;



}TypeContainer;

TypeContainer *NewTypeContainer();


#endif
