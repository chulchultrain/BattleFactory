#ifndef __POKEMONSTATS_H_INCLUDED__
#define __POKEMONSTATS_H_INCLUDED__

typedef struct PokemonStatsPrivate PokemonStatsPrivate;

/*

void SetL(PokemonStats *this, unsigned int level);
void SetHP(PokemonStats* this, unsigned int HitPoints);
void SetA(PokemonStats* this, unsigned int Attack);
void SetD(PokemonStats* this, unsigned int Defense);
void SetSpA(PokemonStats* this, unsigned int SpecialAttack);
void SetSpD(PokemonStats* this, unsigned int SpecialDefense);
void SetS(PokemonStats* this, unsigned int Speed);

unsigned int GetHP(PokemonStats *this);
unsigned int GetA(PokemonStats *this);
unsigned int GetD(PokemonStats *this);
unsigned int GetSpA(PokemonStats *this);
unsigned int GetSpD(PokemonStats *this);
unsigned int GetS(PokemonStats *this);
unsigned int GetL(PokemonStats *this);

void ConsolePrint(PokemonStats *this);
*/

typedef struct PokemonStats{

PokemonStatsPrivate *mem;

void (*SetL)();
void (*SetHP)();
void (*SetA)();
void (*SetD)();
void (*SetSpA)();
void (*SetSpD)();
void (*SetS)();
void (*ConsolePrint)();

unsigned int(*GetL)();
unsigned int(*GetHP)();
unsigned int(*GetA)();
unsigned int(*GetD)();
unsigned int(*GetSpA)();
unsigned int(*GetSpD)();
unsigned int(*GetS)();

}PokemonStats;

PokemonStats* NewPokemonStats(); //function def cant be seen in main function

PokemonStats* CopyPokemonStats(PokemonStats* pokemonStats); //copy constructor

PokemonStats* FullNewPokemonStats(const unsigned int HP,const unsigned int A,const unsigned int D,const unsigned int SpA, const unsigned int SpD, const unsigned int S); //driver

void DeletePokemonStats(PokemonStats* recall);



void ResetPokemonStatsData(PokemonStats* recall);

//void ResetPokemonStatsPointers(PokemonStats* recall);

void ResetPokemonStatsAll(PokemonStats* recall);


#endif

