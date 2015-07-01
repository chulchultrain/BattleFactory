#ifndef __TYPING_H_INCLUDED__
#define __TYPING_H_INCLUDED__

typedef enum Type { NONE, NORMAL, GRASS, BUG, FIRE, WATER, LIGHTNING, FLYING, ROCK, GROUND, POISON, PSYCHIC, DARK, STEEL, DRAGON }Type;

typedef struct TypeContainer{


Type primary;
Type secondary;



}TypeContainer;

TypeContainer *NewTypeContainer();

TypeContainer *CopyTypeContainer(TypeContainer* original);

//driver to insert Types into a TypeContainer
TypeContainer *FullTypeContainer(Type* type1, Type* type2);


//TODO:delete TypeContainer function
void DeleteTypeContainer(TypeContainer* recall);

#endif


