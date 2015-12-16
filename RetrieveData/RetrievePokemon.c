#include <RetrieveData/RetrievePokemon.h>
#include <BF_Special_Util/Special_Util.h>
#include <SpecialConstants/SpecialConstants.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdio.h>
#include <stdlib.h>


void ConsolePrintPokemonEntryFile(FILE *fin);
void GoToEntryChoice(FILE *fin, unsigned int choice);
Type TokenToType(char *token);
MoveCategory TokenToCategory(char *token);
void TypeLineIntoEntry(char *typeLine,PokemonEntry *pEntry);
void MoveLineIntoEntry(char *moveLine, PokemonEntry *pEntry, unsigned int choice);
unsigned int CorrectRegionPrompt(char *entryFileDir, unsigned int fileDirLimit);
void EntryDataIntoPokemonEntry(PokemonEntry *pEntry,unsigned int choice);
void ProcessBaseStatsFile(FILE *fptr, unsigned int *statArray, unsigned int statArrayLimit);
void GetBaseStatsForPokemonName(char *name, unsigned int name_limit, unsigned int *statArray, unsigned int statArrayLimit);
void StatsIntoEntry(PokemonEntry *pEntry);
void AugmentEntryByNatureLine(char *natureLine,pEntry);
PokemonEntry *EntryFromNameChoice(char *name, unsigned int choice);



void PrintDamageBetweenEntries(PokemonEntry *pEntry1, PokemonEntry *pEntry2)

void TopLevel(char *name);


void ConsolePrintPokemonEntryFile(FILE *fin) {
if( fin != 0) {
	char line[MAX_POKEDEX_LINE] = {0};
	while( fgets(line,MAX_POKEDEX_LINE - 5, fin) != 0) 
		printf("%s", line); 
				}


}


void GoToEntryChoice(FILE *fin, unsigned int choice) {
	unsigned int i = 0;
	char line[MAX_POKEDEX_LINE] = {0};
	for(i = 0; i < choice; i++) {
		while( line[0] != '\n')
			if(fgets(line,MAX_POKEDEX_LINE - 5, fin) == 0)
				GlobalDestroyer(1,0,0);
	}
}

Type TokenToType(char *token) {
	switch(token[0]) {
		case 'B': return BUG;
		case 'D': 
			switch(token[1]) {
				case 'a': return DARK;
				case 'r': return DRAGON;
				}
		case 'E': return ELECTRIC;
		case 'F':
			switch(token[1]) {
				case 'a':
					return FAIRY;
				case 'i': 
				switch(line[2]):
					case 'g': return FIGHTING;	
					case 'i': return FIRE;
				case 'l': return FLYING;
				}
		case 'G':
			switch(token[2]) {
				case 'a': return GRASS;
				case 'o': return GROUND;
				}
		case 'I': return ICE;
		case 'N': return NORMAL;
		case 'P': switch(token[1]) {
				case 'o': return POISON;
				case 's': return PSYCHIC;
				}
		case 'R': return ROCK;
		case 'S': return STEEL;
		case 'W': return WATER;
	}	
	return NONE;

}

MoveCategory TokenToCategory(char *token) {

	switch(token[0]) {
		case 'P': return PHYSICAL;
		case 'S': 
			switch(token[1]) {
				case 'p': return SPECIAL;
				case 't': return STATUS;
				}
	}
	return EMPTY;
}


void TypeLineIntoEntry(char *typeLine,PokemonEntry *pEntry) {

	unsigned int i = 0;
	unsigned int hasTwoTypes = 0;
	for(i = 0; typeLine[0] != 0 && i < MAX_LINE_LENGTH; i++)
		if( typeLine[i] == '/') {
			hasTwoTypes = 1;
			i += 1;
			break; }
		
	//TODO:CHANGE POKEMONENTRY TO accept values not pointers and then change these accordingly.
	Type t1 = TokenToType(typeLine);
	Type t2 = NONE;
	if( hasTwoTypes == 1) {
		t2 = TokenToType(typeLine + i);
	}
	pEntry->SetPrimaryType(pEntry,t1);
	pEntry->SetSecondaryType(pEntry,t2);
}

void MoveLineIntoEntry(char *moveLine, PokemonEntry *pEntry, unsigned int choice) {

	int i;
	char indexString[MAX_LINE_LENGTH] = {0};
	char moveName[MAX_NAME] = {0};
	char typeString[MAX_NAME] = {0};
	char categoryString[MAX_NAME] = {0};
	char damageString[MAX_NAME] = {0};
	char inputFileName[MAX_FILE_NAME] = MOVES_DIRECTORY;

	unsigned int moveIndex[1];
	unsigned int moveDamage[1];

	for(i = 0; i < MAX_LINE_LENGTH && moveLine[i] >= '0' && moveLine[i] <= '9'; i++)
		indexString[i] = moveLine[i];
	AppendArrayToArray(indexString, MAX_LINE_LENGTH, inputFileName, MAX_FILE_NAME);

	FILE *fin = fopen(inputFileName,"r");

	//read data into char arrays
	SafeReadLine(indexString,MAX_LINE_LENGTH,fin,1);
	SafeReadLineRNL(moveName,MAX_NAME,fin,1);
	SafeReadLine(typeString,MAX_NAME,fin,1);
	SafeReadLine(categoryString,MAX_NAME,fin,1);
	SafeReadLine(damageString,MAX_NAME,fin,1);
	
	//filter char array data
	StringToUnsignedInt(indexString,MAX_LINE_LENGTH,moveIndex);
	StringToUnsignedInt(damageString,MAX_NAME,moveDamage);
	Type moveType = TokenToType(typeString);
	MoveCategory moveCategory = TokenToCategory(categoryString);

	switch(choice) {

	case 0:
		pEntry->SetFirstMove(pEntry, moveName, moveDamage[0], moveType, moveCategory);
		break;
	case 1:
		pEntry->SetSecondMove(pEntry, moveName, moveDamage[0], moveType, moveCategory);
		break;
	case 2:
		pEntry->SetThirdMove(pEntry, moveName, moveDamage[0], moveType, moveCategory);
		break;
	case 3:
		pEntry->SetFourthMove(pEntry, moveName, moveDamage[0], moveType, moveCategory);
		break;
	}	
	
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

void AugmentEntryByNatureLine(char *natureLine,PokemonEntry *pEntry) {
	
}

//Augments the pokemonEntry based on which selection was made. 0,1,2,3
void EntryDataIntoEntry(PokemonEntry *pEntry,unsigned int choice) {

	char entryFileName[MAX_FILE_NAME] = ENTRY_DIRECTORY;
	char name[MAX_NAME] = {0};
	pEntry->GetName(pEntry,name,MAX_NAME);
	CorrectRegionPrompt(entryFileName, MAX_FILE_NAME);
	AppendArrayToArray(name, MAX_NAME, entryFileName, MAX_FILE_NAME);

	FILE *fin = fopen(entryFileName,"r");
	if(fin == 0) {
		GlobalDestroyer(1,0,0);
	}
	else 
		printf("Successful open\n");

	//move file pointer to correct position in file, then parse data
	GoToEntryChoice(fin,choice);
	char typeLine[MAX_LINE_LENGTH] = {0};
	char moveLine[MAX_LINE_LENGTH] = {0};
	char itemLine[MAX_LINE_LENGTH] = {0};
	char natureLine[MAX_LINE_LENGTH] = {0};
	SafeReadLine(typeLine,MAX_LINE_LENGTH, fin,1);
	TypeLineIntoEntry(typeLine,pEntry);

	int i = 0;
	while( i < 4) {
		SafeReadLine(moveLine,MAX_LINE_LENGTH - 5, fin,1);
		MoveLineIntoEntry(moveLine,pEntry,i);
		i++;
	}

	SafeReadLine(itemLine,MAX_LINE_LENGTH,fin,1);
	SafeReadLine(natureLine,MAX_LINE_LENGTH,fin,1);
	
	AugmentEntryByNature(natureLine,pEntry);

	fclose(fin);
}


// the file should have each stat on a different line, statName statAmount 
void ProcessBaseStatsFile(FILE *fptr, unsigned int *statArray, unsigned int statArrayLimit) {

	unsigned int i = 0; //array offset
	char buffer[MAX_LINE_LENGTH] = {0};

	while(i < statArrayLimit && fgets(buffer, MAX_LINE_LENGTH, fptr) != 0) {

		StringToUnsignedInt(buffer, MAX_LINE_LENGTH, (statArray + i) );
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



void StatsIntoEntry(PokemonEntry *pEntry) {
	char name[MAX_NAME] = {0};
	pEntry->GetName(pEntry,name,MAX_NAME);
	unsigned int statTable[NUM_OF_STATS];
	GetBaseStatsForPokemonName(name, MAX_NAME, statTable, NUM_OF_STATS);

	pEntry->SetHitPoints(pEntry, statTable[0]);
	pEntry->SetAttack(pEntry, statTable[1]);
	pEntry->SetDefense(pEntry, statTable[2]);
	pEntry->SetSpecialAttack(pEntry, statTable[3]);
	pEntry->SetSpecialDefense(pEntry, statTable[4]);
	pEntry->SetSpeed(pEntry, statTable[5]);	
		
}

PokemonEntry *EntryFromNameChoice(char *name, unsigned int choice) {
	PokemonEntry *pEntry = NewPokemonEntry();
	pEntry->SetName(pEntry, name);

	StatsIntoEntry(pEntry);
	EntryDataIntoEntry(pEntry,choice);

	return pEntry;

}

void PrintDamageBetweenEntries(PokemonEntry *pEntry1, PokemonEntry *pEntry2) {
	unsigned int OnetoTwo[MAX_NUM_MOVES];
	unsigned int TwotoOne[MAX_NUM_MOVES];

	
	
}


void TopLevel(char *name) {

	PokemonEntry *pEntry = EntryFromNameChoice(name,1);
	pEntry->ConsolePrint(pEntry);

}

