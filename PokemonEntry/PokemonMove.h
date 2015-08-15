#ifndef __POKEMONMOVE_H_INCLUDED__
#define __POKEMONMONVE_H_INCLUDED__


typedef struct PokemonMovePrivate PokemonMovePrivate;


typedef struct PokemonMove {

PokemonMovePrivate *mem;

//Set Move Name
void (*SetName)();
void (*GetName)();
void (*ConsolePrint)();


} PokemonMove;

PokemonMove *NewPokemonMove();

void ResetPokemonMoveData(PokemonMove *recall);

void DestroyPokemonMove(PokemonMove *recall);



#endif
