#ifndef __GLOBALDESTROYER_H_INCLUDED__
#define __GLOBALDESTROYER_H_INCLUDED__

/*
Global destroyer is a function that keeps records of the objects created.
Whenever the objects' destroyers are called, GlobalDestroyer loses the record of that object. 
At the end of the program lifetime, GlobalDestroyer will destroy all the objects it has records of, so the programmer doesn't have to.

At the top-most level, only one call should really be made. That is GlobalDestroyer(1,0,0); whenever you wish the program to terminate.

Below are more advanced uses of GlobalDestroyer for a more managed version of memory.
*/

/*
typedef struct PokemonEntry PokemonEntry;
typedef struct Pokedex Pokedex;
typedef struct BattleSim Battlesim;
*/
typedef enum ALLTYPES{
	NOTHING, POKEDEX, POKEMONENTRY, BATTLESIMULATION
} ALLTYPES;

/*

More uses. 

How to use:

Parameters:

int mallocFailFlag: only has a defined use for certain values. Will do nothing otherwise.
0 - indicates you are creating a new object and you want to add this object to the record table.
1 - indicates a program failure, and you want the program to terminate without memory leaks, so you destroy every object you have a record of.
2 - indicates you want to remove an object from the record table.

void *obj -  It is a pointer to the object you wish to add or remove from the record table. This parameter only matters when used with
mallocfailflag of 0 or 2.

ALLTYPES enumerator: tells the destroyer what kind of object the pointer is so that it can be properly cast into a pointer of that type.



*/

void GlobalDestroyer(int mallocFailFlag, void *obj, ALLTYPES type);

#endif
