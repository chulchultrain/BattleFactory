#ifndef __POKEMONSTATS_H_INCLUDED__
#define __POKEMONSTATS_H_INCLUDED__

typedef struct PokemonStatsPrivate PokemonStatsPrivate;

typedef struct PokemonStats{

PokemonStatsPrivate *mem;

void (*SetHP)();
void (*SetA)();
void (*SetD)();
void (*SetSpA)();
void (*SetSpD)();
void (*SetS)();
void (*ConsolePrint)();

}PokemonStats;

PokemonStats* NewPokemonStats(); //function def cant be seen in main function

PokemonStats* CopyPokemonStats(PokemonStats* pokemonStats); //copy constructor

PokemonStats* FullNewPokemonStats(const int* HP,const int* A,const int* D,const int* SpA, const int* SpD, const int* S); //driver

void DeletePokemonStats(PokemonStats* recall);



void ResetPokemonStatsData(PokemonStats* recall);

void ResetPokemonStatsPointers(PokemonStats* recall);

void ResetPokemonStatsAll(PokemonStats* recall);


#endif

//TODO:delete pokemonStats function
