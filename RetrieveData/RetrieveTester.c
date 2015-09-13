#include <RetrieveData/RetrievePokemon.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

//TODO:change with makefile to nonmagic value
char buffer[21] = {0};

printf("The Application to Help Get Higher Records in Pokemon Platinum Battle Factory\n");

char continueChar = 'Y';

int i;

while(continueChar == 'Y') {
printf("Enter Pokemon Name you which to find. ");
fgets(buffer,21,stdin);

//modulize
i = 0;
while(i < 21 && buffer[i] != '\n')
	i++;
buffer[i] = 0;


ConsolePrintPokemonEntryFile(buffer);
printf("To continue with another pokemon, type in Y. ");
continueChar = fgetc(stdin);
}
return 0;

}
