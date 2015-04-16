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

#endif
