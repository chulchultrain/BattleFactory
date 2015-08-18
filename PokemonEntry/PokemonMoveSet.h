#ifndef __POKEMONMOVESET_H_INCLUDED__
#define __POKEMONMOVESET_H_INCLUDED__


typedef struct PokemonMoveSetPrivate PokemonMoveSetPrivate;


typedef struct PokemonMoveSet {
	PokemonMoveSetPrivate *mem;


void (*SetFirstMove)();
void (*SetSecondMove)();
void (*SetThirdMove)();
void (*SetFourthMove)();
void (*GetFirstMove)();
void (*GetSecondMove)();
void (*GetThirdMove)();
void (*GetFourthMove)();
void (*ConsolePrint)();


} PokemonMoveSet;

PokemonMoveSet *NewPokemonMoveSet();

void DeletePokemonMoveSet(PokemonMoveSet *recall);


#endif
