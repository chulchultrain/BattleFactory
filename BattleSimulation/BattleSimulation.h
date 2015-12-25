#ifndef __BATTLESIMULATION_H_INCLUDED__
#define __BATTLESIMULATION_H_INCLUDED__

#include <PokemonEntry/PokemonEntry.h>


typedef struct BattleSimPrivate BattleSimPrivate;

typedef struct BattleSim{

BattleSimPrivate *mem;


void (*Initialize)();
void (*Simulate)();
void (*ConsolePrint)();
} BattleSim;

BattleSim *NewBattleSim();

void DeleteBattleSim(BattleSim *obj);


#endif
