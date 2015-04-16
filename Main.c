#include <stdio.h>
#include <stdlib.h>
#include "PokemonEntry.h"



int main() {

PokemonEntry hi;

hi.typeData.primary = DARK;
hi.typeData.secondary = NORMAL;

PokemonStats *pokeStats = NewPokemonStats();
int sd = pokeStats->Speed;
printf("%d\n", sd);


return 0;
}
