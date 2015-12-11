#include <RetrieveData/RetrievePokemon.h>
#include <BF_Special_Util/Special_Util.h>
#include <SpecialConstants/SpecialConstants.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdio.h>
#include <stdlib.h>


void ConsolePrintPokemonEntryFile(FILE *fin) {
/**
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
**/
if( fin != 0) {
	char line[MAX_POKEDEX_LINE] = {0};
	while( fgets(line,MAX_POKEDEX_LINE - 5, fin) != 0) 
		printf("%s", line); 
					}
//fclose(fin);


}


// the file should have each stat on a different line, statName statAmount 
void ProcessBaseStatsFile(FILE *fptr, unsigned int *statArray, unsigned int statArrayLimit) {

	unsigned int i = 0; //array offset
	int val = 0;
	char buffer[MAX_LINE_LENGTH] = {0};

	while(i < statArrayLimit && fgets(buffer, MAX_LINE_LENGTH, fptr) != 0) {

		val = StringToUnsignedInt(buffer, MAX_LINE_LENGTH, (statArray + i) );
		//add Logger function to indicate failure. 
		i++;
	}

}

void GetBaseStatsForPokemonName(char *name, unsigned int name_limit, unsigned int *statArray, unsigned int statArrayLimit) {
	char fileName[MAX_FILE_NAME] = BASE_STATS_DIR;
	AppendArrayToArray(name, name_limit, fileName, MAX_FILE_NAME);
	
	printf("base stat file name is %s\n", fileName);

	FILE *fin = fopen(fileName, "r");
	if(fin == 0) {
		GlobalDestroyer(1,0,0);
	}
	//Extracts base stats out of file and put into array.
	ProcessBaseStatsFile(fin, statArray, statArrayLimit);
	fclose(fin);
}




unsigned int CorrectRegionPrompt(char *entryFileDir, unsigned int fileDirLimit) {

	//char entryFileName[MAX_FILE_NAME] = ENTRY_DIRECTORY;

	
	char EMERALD_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_EMERALD;
	char DPP_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_DPP;
	char HGSS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_HGSS;
	char BW_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW;
	char BW2_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW2;
	char XY_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_XY;
	char ORAS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_ORAS;

	char *regionPointer[MAX_REGIONS] = {EMERALD_R, DPP_R, HGSS_R, BW_R, BW2_R, XY_R, ORAS_R};

	printf("Choose which game by typing an integer\n");
	unsigned int i;

	for(i = 0; i < MAX_REGIONS && regionPointer[i] != 0; i++)
		printf("%s - %u\n", regionPointer[i], i);	

	char buffer[MAX_LINE_LENGTH];
	unsigned int uPtr[1];	

	fgets(buffer,MAX_LINE_LENGTH,stdin);
	if( !StringToUnsignedInt(buffer, MAX_LINE_LENGTH, uPtr) ) {
		AppendArrayToArray( *(regionPointer + uPtr[0]), MAX_REGION_SUBDIR_LENGTH, entryFileDir, fileDirLimit);
		return 0; }
	else 
		return 1; // something idk maybe an error msg. maybe return function shoudl also error 0,1

}



void TopLevel(char *name, unsigned int name_limit) {

	unsigned int statTable[NUM_OF_STATS];
	GetBaseStatsForPokemonName(name, name_limit, statTable, NUM_OF_STATS);
	
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

	pEntry->ConsolePrint(pEntry);
	//choose region/game for correct BF entries



	char entryFileName[MAX_FILE_NAME] = ENTRY_DIRECTORY;

	unsigned int errorMsg = CorrectRegionPrompt(entryFileName, MAX_FILE_NAME);

	AppendArrayToArray(name, MAX_NAME, entryFileName, MAX_FILE_NAME);
	
	//make a char for rest of entries

	printf("EntryFileName is %s\n", entryFileName);
	FILE *fin = fopen(entryFileName,"r");
	if(fin == 0) {
		GlobalDestroyer(1,0,0);
	}
	else 
		printf("Successful open\n");

	//display entries
	ConsolePrintPokemonEntryFile(fin);

	//TODO: DBL FREE ERROR DUE TO CONSOLEPRINTPOKEMONENTRY CLOSING FILE 
	fclose(fin);

	//choose which entries.
	printf("Which Entry would you like to pick? ");

	//make func to order entries and efficiently retrieve. not multiple file Open and close

	

}





/**
void EntryFromFile(PokemonEntry *entry, FILE *fptr, unsigned int whichEntry) {

	//char fileName[MAX_FILE_NAME] = ENTRY_DIRECTORY SUB_DIR_DPP;

	//create PokemonEntry, with name.
	//based on whichEntry, parse out the correct entry, and update stats, nature, moveset accordingly

}

**/

