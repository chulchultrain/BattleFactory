#include <PokemonEntry/PokemonEntry.h>


typedef struct BattleSimPrivate BattleSimPrivate;

typedef struct BattleSim{

BattleSimPrivate *mem;

void SetEntry1(BattleSim *original, PokemonEntry *obj);
void SetEntry2(BattleSim *original, PokemonEntry *obj);

void CalcMoveDamages(BattleSim *original);
void ConsolePrint(BattleSim *obj);
} BattleSim;


