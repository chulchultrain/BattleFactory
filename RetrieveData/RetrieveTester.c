#include <RetrieveData/RetrievePokemon.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <SpecialConstants/SpecialConstants.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

//TODO:change with makefile to nonmagic value
char buffer[MAX_NAME] = {0};

printf("The Application to Help Get Higher Records in Pokemon Platinum Battle Factory\n");

char continueChar = 'Y';

int i;

while(continueChar == 'Y') {
	printf("Enter Pokemon Name you which to find. ");
	fgets(buffer,MAX_NAME,stdin);
	//fflush(stdin);
	//modulize
	i = 0;
	while(i < MAX_NAME && buffer[i] != '\n')
		i++;
	buffer[i] = 0;


	PokemonEntry *entry = EntryFromData(buffer,0,0,100);
	printf("To continue with another pokemon, type in Y. ");
	//fflush(stdin); cant flush input buffers according to internet
	//TODO:NewLINE errors. reads newline that wasn't taken out of stdin.
	continueChar = fgetc(stdin);
	printf("Continue char is %c\n", continueChar);
	
}

GlobalDestroyer(1,0,0);
return 0;

}
