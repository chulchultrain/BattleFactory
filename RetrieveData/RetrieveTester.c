#include <RetrieveData/RetrievePokemon.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <SpecialConstants/SpecialConstants.h>
#include <BF_Special_Util/Special_Util.h>
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
	i = 0;
	while(i < MAX_NAME && buffer[i] != '\n')
		i++;
	buffer[i] = 0;
	EntryOptions options;
	options.level = 100;
	options.IV = 0;
	options.region = 1;
	options.choice = 1;
	copyName(buffer,options.name);

	PokemonEntry *pEntry = NewEntryFromData(options);	
	pEntry->ConsolePrint(pEntry);
	continueChar = fgetc(stdin);
	printf("Continue char is %c\n", continueChar);
	
}

GlobalDestroyer(1,0,0);
return 0;

}
