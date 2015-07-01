#include <stdio.h>
#include <stdlib.h>
#include "PokemonEntry.h"


int main() {

int a, b, c, d, e, f;
a = 10;
b = 11;
c = 12;
d = 13;
e = 14;
f = 15;

Type *alpha = malloc(sizeof(Type));
*alpha = NONE;
Type *beta = malloc(sizeof(Type));
*beta = DARK;

PokemonStats *stats = FullNewPokemonStats(&a,&b,&c,&d,&e,&f);
TypeContainer *type = FullTypeContainer(alpha, beta);
//printf("%d\n", stats->HitPoints);

char QQ[] = {"Metagross"};




PokemonEntry *blood = FullPokemonEntry(QQ, stats, type);
printf("Before: blood primary Type is %d\n", blood->typeData->primary);
*alpha = PSYCHIC;
printf("After change alpha: blood primary Type is %d\n", blood->typeData->primary);
SetPrimaryType(blood->typeData, alpha);
printf("After Set: blood primary Type is %d\n", blood->typeData->primary);
*alpha = GRASS;
printf("After change alpha: blood primary Type is %d\n", blood->typeData->primary);

DeletePokemonEntry(blood);
DeletePokemonStats(stats);
DeleteTypeContainer(type);

return 0;
}
