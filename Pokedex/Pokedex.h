/**
23 July 2015 - Creation. Only name and type useful info for battle factory predictor right now. Not trying to recode the entire pokemon framework. 
This is for use in a simple hash table. Don't need indirection through function pointers for the individual entries. Pokedex struct will have Function pointers.

It would be much safer, but each instance would need it, and its benefits do not seem as great here. I know that pokemonentry, pokemonstats, and typecontainer all have this. But, here I arbitrarily make the decision for less overhead over convenience in OOP. 

The Pokedex cannot be changed freely, and PokedexEntries are only used in the pokedex, so PokedexEntry public, and Pokedex opaque.

I feel like I have done enough OOP in the  3 structs mentioned earlier.  

**/
#ifndef __POKEDEX_H_INCLUDED__
#define __POKEDEX_H_INCLUDED__


#ifndef MAX_NAME
#define MAX_NAME 21
#endif


//only accounting for up to Gen IV. 
#ifndef MAX_POKEMON_NUMBER
#define MAX_POKEMON_NUMBER 494
#endif


#include <PokemonEntry/Typing.h>

typedef struct PokedexEntry PokedexEntry;

struct PokedexEntry {

unsigned int ID;
char name[MAX_NAME];
Type primary;
Type secondary;
PokedexEntry *next;


};

/**
Goal: Make array of Pokedex entries. No need for hashtable/hashfunctions because each pokemon has a unique numerical ID. 
**/
typedef struct PokedexPrivate PokedexPrivate;

typedef struct Pokedex {

PokedexPrivate *mem;

/**
PutInTable
Lookup
Retrieve
ConsolePrintEntry
**/	

}Pokedex;


Pokedex *NewPokedex();

void SetPokedexEntryInPokedex(Pokedex *original, PokedexEntry *obj);

void ConsolePrintPokedexEntryInPokedex(Pokedex *obj, char *name);

void DestroyPokedex(Pokedex *recall);

#endif
