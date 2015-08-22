#ifndef __GLOBALDESTROYER_H_INCLUDED__
#define __GLOBALDESTROYER_H_INCLUDED__


//global destroyer is included to exit application with minimal memory leaks in case of memory allocation failure

typedef struct PokemonEntry PokemonEntry;
typedef struct Pokedex Pokedex;

typedef enum ALLTYPES{
	NOTHING, POKEDEX, POKEMONENTRY
//, BATTLESIMULATION
} ALLTYPES;

void GlobalDestroyer(int mallocFailFlag, void *obj, ALLTYPES type);

#endif
