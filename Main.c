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
SetName(blood, KL);
printf("Set: name is %s\n", blood->name);

DeletePokemonEntry(blood);
DeletePokemonStats(stats);
DeleteTypeContainer(type);

return 0;
}
