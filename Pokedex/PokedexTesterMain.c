#include <stdio.h>
#include <stdlib.h>
#include <Pokedex/Pokedex.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <PokemonEntry/PokemonEntry.h>


int main() {

PokemonEntry *entry = NewPokemonEntry();

PokedexEntry hbox = {133, "metagross", FIRE, WATER, 0};

PokedexEntry derp = {199, "&", FIRE, ICE, 0};

Pokedex *dexter = NewPokedex();

GlobalDestroyer(0, entry, dexter);

printf("After constructor\n");
printf("Dexter is %p\n", dexter);
printf("Hbox is %p\n", &hbox);
SetPokedexEntryInPokedex(dexter, &hbox);
printf("After Setting\n\n\n");
ConsolePrintPokedexEntryInPokedex(dexter, hbox.name);
SetPokedexEntryInPokedex(dexter, &derp);
ConsolePrintPokedexEntryInPokedex(dexter, derp.name);
GlobalDestroyer(1, 0, 0);
printf("After Destroy\n");

return 0;

}
