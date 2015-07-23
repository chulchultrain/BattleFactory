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

unsigned int(*GetHP)();
unsigned int(*GetA)();
unsigned int(*GetD)();
unsigned int(*GetSpA)();
unsigned int(*GetSpD)();
unsigned int(*GetS)();

}PokemonStats;

PokemonStats* NewPokemonStats(); //function def cant be seen in main function

PokemonStats* CopyPokemonStats(PokemonStats* pokemonStats); //copy constructor

PokemonStats* FullNewPokemonStats(const unsigned int* HP,const unsigned int* A,const unsigned int* D,const unsigned int* SpA, const unsigned int* SpD, const unsigned int* S); //driver

void DeletePokemonStats(PokemonStats* recall);



void ResetPokemonStatsData(PokemonStats* recall);

//void ResetPokemonStatsPointers(PokemonStats* recall);

void ResetPokemonStatsAll(PokemonStats* recall);


#endif

