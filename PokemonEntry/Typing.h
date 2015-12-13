#ifndef __TYPING_H_INCLUDED__
#define __TYPING_H_INCLUDED__

typedef enum Type { NONE, NORMAL, GRASS, BUG, FIRE, WATER, ICE, ELECTRIC, FLYING, ROCK, GROUND, POISON, PSYCHIC, DARK, STEEL, DRAGON }Type;

typedef struct TypeContainerPrivate TypeContainerPrivate;


/*
void SetPrimary(TypeContainer *this, Type primary);
void SetSecondary(TypeContainer *this, Type secondary);
void SetBoth(TypeContainer *this, Type primary, Type secondary);

Type GetPrimary(TypeContainer *this);
Type GetSecondary(TypeContainer *this);

void ConsolePrint(TypeContainer *this);
*/

typedef struct TypeContainer{

TypeContainerPrivate *mem;

void (*SetPrimary)(); 
void (*SetSecondary)(); 
void (*SetBoth)();

void (*ConsolePrint)();
Type (*GetPrimary)();
Type (*GetSecondary)();

}TypeContainer;

TypeContainer *NewTypeContainer();

TypeContainer *CopyTypeContainer(TypeContainer* original);

//driver to insert Types into a TypeContainer
TypeContainer *FullTypeContainer(Type type1, Type type2);

void DeleteTypeContainer(TypeContainer* recall);



void ResetTypeContainerData(TypeContainer* recall);
//definitely need to get rid of resetpointer functions. Could lead to alot of problems.
//void ResetTypeContainerPointers(TypeContainer* recall);

void ResetTypeContainerAll(TypeContainer* recall);


#endif


