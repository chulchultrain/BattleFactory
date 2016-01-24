#ifndef __BATTLESIMULATION_H_INCLUDED__
#define __BATTLESIMULATION_H_INCLUDED__

#include <PokemonEntry/PokemonEntry.h>

/*
void Initialize(BattleSim *obj, PokemonEntry *e1, PokemonEntry *e2);
void Simulate(BattleSim *obj);
void ConsolePrint(BattleSim *obj);

*/


typedef struct BattleSimPrivate BattleSimPrivate;

typedef struct BattleSim{

BattleSimPrivate *mem;


void (*Initialize)();
void (*Simulate)();
void (*ConsolePrint)();
void (*FilePrint)();
//void (*Configure)();
} BattleSim;

BattleSim *NewBattleSim();

void DeleteBattleSim(BattleSim *obj);


#endif
