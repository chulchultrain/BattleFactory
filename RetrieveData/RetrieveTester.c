#include <RetrieveData/RetrievePokemon.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

//TODO:change with makefile to nonmagic value
char buffer[21] = {0};

printf("The Application to Help Get Higher Records in Pokemon Platinum Battle Factory\n");

unsigned int toContinue = 1;

while(toContinue == 1) {

fgets(buffer,21,stdin);
ConsolePrintPokemonEntryFile(buffer);
fgetc(buffer,21,stdin);
}
return 0;

}
