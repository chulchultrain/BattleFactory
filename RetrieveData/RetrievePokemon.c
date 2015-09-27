#include <RetrieveData/RetrievePokemon.h>
#include <BF_Special_Util/Special_Util.h>
#include <SpecialConstants/SpecialConstants.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdio.h>
#include <stdlib.h>


void ConsolePrintPokemonEntryFile(char *name) {

char fileName[MAX_FILE_NAME] = ENTRY_DIRECTORY SUB_DIR_DPP;
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

/**

void TopLevel(char *name) {
	unsigned int statTable[NUM_OF_STATS];
	GetBaseStatsForPokemonName(name, MAX_NAME, statTable, NUM_OF_STATS);
	
	unsigned int i = 0;


	//create entry using basestats and name.
	PokemonEntry *pEntry = NewPokemonEntry();
	pEntry->SetName(pEntry, name);
	pEntry->SetHitPoints(pEntry, statTable);
	pEntry->SetAttack(pEntry, (statTable + 1));
	pEntry->SetDefense(pEntry, (statTable + 2));
	pEntry->SetSpecialAttack(pEntry, (statTable + 3));
	pEntry->SetSpecialDefense(pEntry, (statTable + 4));
	pEntry->SetSpeed(pEntry, (statTable + 5));



}

// the file should have each stat on a different line, statName statAmount 
void ProcessBaseStatsFile(FILE *fptr, unsigned int *statArray, unsigned int statArrayLimit) {

	unsigned int i = 0; //array offset
	int val = 0;
	char buffer[MAX_LINE_LENGTH] = {0};

	while(i < statArrayLimit && fgets(buffer, MAX_LINE_LENGTH, fptr != 0)) {

		val = StringToUnsignedInt(buffer, MAX_LINE_LENGTH, (statArray + i) );
		//add Logger function to indicate failure. 
		i++;
	}

}

void GetBaseStatsForPokemonName(char *name, unsigned int name_limit, unsigned int *statArray, unsigned int statArrayLimit) {
	char fileName[MAX_FILE_NAME] = BASE_STATS_DIR;
	AppendArrayToArray(name, name_limit, fileName, MAX_FILE_NAME);
	
	FILE *fin = fopen(fileName, "r");
	if(fin == 0) {
		GlobalDFestroyer(1,0,0);
	}
	//Extracts base stats out of file and put into array.
	ProcessBaseStatsFile(fin, statArray, statArrayLimit);
}
**/


/**
void EntryFromFile(PokemonEntry *entry, unsigned int whichEntry) {

	//create PokemonEntry, with name.
	//based on whichEntry, parse out the correct entry, and update stats, nature, moveset accordingly

}

**/

