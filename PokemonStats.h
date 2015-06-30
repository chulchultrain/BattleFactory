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


PokemonStats* FullNewPokemonStats(const int* HP,const int* A,const int* D,const int* SpA, const int* SpD, const int* S);
#endif
