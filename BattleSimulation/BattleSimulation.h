#ifndef __BATTLESIMULATION_H_INCLUDED__
#define __BATTLESIMULATION_H_INCLUDED__

#include <PokemonEntry/PokemonEntry.h>
#include <SpecialConstants/SpecialConstants.h>
/*
void Initialize(BattleSim *obj, PokemonEntry *e1, PokemonEntry *e2);
void Simulate(BattleSim *obj);
void ConsolePrint(BattleSim *obj);

*/


typedef struct MoveDamage {

//	char name[MAX_NAME];
	unsigned int lowerBound,upperBound;
} MoveDamage;

typedef struct BattleSimPrivate BattleSimPrivate;

typedef struct BattleSim BattleSim;

struct BattleSim{

BattleSimPrivate *mem;

//void (*Menu)();
//void (*ConsoleInput)();
//void (*FileInput)();
void (*Simulate)(BattleSim *obj);
//void (*ConsolePrint)(BattleSim *obj);
//void (*FilePrint)(BattleSim *obj);
void (*Purge)(BattleSim *obj);
//void (*Configure)();
void (*SetEntry1)(BattleSim *obj, PokemonEntry *e);
void (*SetEntry2)(BattleSim *obj, PokemonEntry *e);
};

BattleSim *NewBattleSim();

void DeleteBattleSim(BattleSim *obj);

/*
	Only Relevant function here as of 06_12_2016
	Use to calculate the upper and lower bounds of a move from an attacker when it hits a defender.
*/
MoveDamage calcMoveDamage(PokemonEntry *attacker, PokemonEntry *defender, unsigned int choice);

#endif
