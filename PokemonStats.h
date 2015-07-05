#ifndef __POKEMONSTATS_H_INCLUDED__
#define __POKEMONSTATS_H_INCLUDED__


typedef struct PokemonStats{

int HitPoints;
int Attack;
int Defense;
int SpecialAttack;
int SpecialDefense;
int Speed;

void (*SetHP)();
void (*SetA)();
void (*SetD)();
void (*SetSpA)();
void (*SetSpD)();
void (*SetS)();
void (*ConsolePrint)();

} PokemonStats;

PokemonStats* NewPokemonStats(); //function def cant be seen in main function

PokemonStats* CopyPokemonStats(PokemonStats* pokemonStats); //copy constructor

PokemonStats* FullNewPokemonStats(const int* HP,const int* A,const int* D,const int* SpA, const int* SpD, const int* S); //driver

void DeletePokemonStats(PokemonStats* recall);

void SetHitPoints(PokemonStats* original, const int* HitPoints);

void SetAttack(PokemonStats* original, const int* Attack);

void SetDefense(PokemonStats* original, const int* Defense);

void SetSpecialAttack(PokemonStats* original, const int* SpecialAttack);

void SetSpecialDefense(PokemonStats* original, const int* SpecialDefense);

void SetSpeed(PokemonStats* original, const int* Speed);

void SetPokemonStatsFunctionPointers(PokemonStats* original);

void ResetPokemonStatsData(PokemonStats* recall);

void ResetPokemonStatsPointers(PokemonStats* recall);

void ResetPokemonStatsAll(PokemonStats* recall);

void PokemonStatsConsolePrint(PokemonStats* obj);


#endif

//TODO:delete pokemonStats function
