#include <stdio.h>
#include <stdlib.h>
#include "PokemonEntry.h"


int main() {

int *a, *b, *c, *d, *e, *f;
a = malloc(sizeof(int));
b = malloc(sizeof(int));
c = malloc(sizeof(int));
d = malloc(sizeof(int));
e = malloc(sizeof(int));
f = malloc(sizeof(int));
*a = 10;
*b = 11;
*c = 12;
*d = 13;
*e = 14;
*f = 15;

Type *alpha = malloc(sizeof(Type));
*alpha = NONE;
Type *beta = malloc(sizeof(Type));
*beta = DARK;

PokemonStats *stats = FullNewPokemonStats(a,b,c,d,e,f);
TypeContainer *type = FullTypeContainer(alpha, beta);
//printf("%d\n", stats->HitPoints);

char QQ[] = {"Metagross"};

char KL[] = {"Zapdos"};
*a = 25;
*b = 26;
*c = 27;
*d = 28;
*e = 29;
*f = 30;


PokemonEntry *blood = FullPokemonEntry(QQ, stats, type);
SetHitPoints(blood->pokeStats, a);
*a = 10;
printf("Set: hitpoints is %d\n", blood->pokeStats->HitPoints);
SetPokemonName(blood, KL);
printf("Set: name is %s\n", blood->name);
TypeContainer *typePtr;
printf("Before: type is %d\n", blood->typeData->primary);
typePtr = blood->typeData;

*beta = WATER;

typePtr->SetPrimary(typePtr, beta);
printf("After:type is %d\n", blood->typeData->primary);

PokemonStats *statsPtr;
statsPtr = blood->pokeStats;
*a = 100000;
statsPtr->SetHP(statsPtr, a);
printf("After:HP is %d\n", blood->pokeStats->HitPoints);

blood->SetName(blood, QQ);
printf("Set: name is %s\n", blood->name);
*f = 2345;
blood->SetHitPoints(blood, f);
printf("Set: HP is %d\n", blood->pokeStats->HitPoints);

TypeContainerConsolePrint(blood->typeData);

DeletePokemonEntry(blood);
DeletePokemonStats(stats);
DeleteTypeContainer(type);
free(a);
free(b);
free(c);
free(d);
free(e);
free(f);
free(alpha);
free(beta);

return 0;
}
