#ifndef __POKEMONSTATS_H_INCLUDED__
#define __POKEMONSTATS_H_INCLUDED__


typedef struct PokemonStats{

int HitPoints;
int Attack;
int Defense;
int SpecialAttack;
int SpecialDefense;
int Speed;


} PokemonStats;

PokemonStats* NewPokemonStats(); //function def cant be seen in main function

PokemonStats* CopyPokemonStats(PokemonStats* pokemonStats); //copy constructor

PokemonStats* FullNewPokemonStats(const int* HP,const int* A,const int* D,const int* SpA, const int* SpD, const int* S); //driver

void DeletePokemonStats(PokemonStats* recall);

#endif

//TODO:delete pokemonStats function
