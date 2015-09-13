#include <RetrieveData/RetrievePokemon.h>
#include <BF_Special_Util/Special_Util.h>
#include <SpecialConstants/SpecialConstants.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdio.h>
#include <stdlib.h>


void ConsolePrintPokemonEntryFile(char *name) {

char fileName[MAX_FILE_NAME] = NAME_DIRECTORY_OF_DATA;
printf("NAME_DIRECTORY_OF_DATA is %s \n", fileName);
int i;
for(i = 0; i < MAX_FILE_NAME; i++)
	if(fileName[i] == 0)
		break;
InsertArrayInArray(name,MAX_NAME,fileName,i,MAX_FILE_NAME);
printf("NAME_DIRECTORY_OF_DATA is %s \n", fileName);
//char fileName2[MAX_FILE_NAME] = "BASE/NAME/Charizard";
FILE *fin = fopen(fileName,"r");
if(fin == 0) {
	GlobalDestroyer(1,0,0);
}
else 
	printf("Successful open\n");

char line[MAX_POKEDEX_LINE] = {0};
while( fgets(line,MAX_POKEDEX_LINE - 5, fin) != 0) 
	printf("%s", line);

fclose(fin);


}
