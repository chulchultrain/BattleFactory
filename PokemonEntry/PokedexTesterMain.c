#include <stdio.h>
#include <stdlib.h>
#include "Pokedex.h"


int main() {

PokedexEntry hbox = {133, "metagross", FIRE, WATER, 0};

Pokedex *dexter = NewPokedex();
printf("After constructor\n");
printf("Dexter is %p\n", dexter);
printf("Hbox is %p\n", &hbox);
SetPokedexEntryInPokedex(dexter, &hbox);
printf("After Setting\n\n\n");
ConsolePrintPokedexEntryInPokedex(dexter, &hbox);
DestroyPokedex(dexter);
printf("After Destroy\n");

return 0;

}
