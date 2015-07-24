#include <stdio.h>
#include <stdlib.h>
#include "Pokedex.h"


int main() {

PokedexEntry hbox = {133, "metagross", FIRE, WATER};

Pokedex *dexter = NewPokedex();
printf("After constructor\n");
SetPokedexEntryInPokedex(dexter, &hbox);
printf("After Setting\n");
ConsolePrintPokedexEntryInPokedex(dexter, 133);
DestroyPokedex(dexter);
printf("After Destroy\n");

return 0;

}
