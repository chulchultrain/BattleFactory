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

Type alpha = NONE;
Type beta = DARK;

PokemonStats *stats = FullNewPokemonStats(&a,&b,&c,&d,&e,&f);
TypeContainer *type = FullTypeContainer(&alpha, &beta);
//printf("%d\n", stats->HitPoints);

char QQ[] = {"Metagross"};




PokemonEntry *blood = FullPokemonEntry(QQ, stats, type);
printf("%s gfawe\n", blood->name);
printf("%d efw\n", blood->pokeStats->HitPoints);
printf("%d daw\n", blood->typeData->secondary);

DeletePokemonEntry(blood);
DeletePokemonStats(stats);
DeleteTypeContainer(type);

return 0;
}
