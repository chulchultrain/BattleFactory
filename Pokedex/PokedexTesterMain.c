#include <stdio.h>
#include <stdlib.h>
#include <Pokedex/Pokedex.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <PokemonEntry/PokemonEntry.h>


int main() {

Pokedex *dexter = NewPokedex();

GlobalDestroyer(0, 0, dexter);

char test[30] = "outputPokedex.txt";
char name[MAX_NAME] = "Metagross";

FillPokedex(dexter, test);
WritePokedexToDirectory(dexter);

ConsolePrintPokedexEntryInPokedex(dexter, name);
GlobalDestroyer(1, 0, 0);
printf("After Destroy\n");

return 0;

}
