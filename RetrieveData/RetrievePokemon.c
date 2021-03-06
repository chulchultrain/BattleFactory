#include <RetrieveData/RetrievePokemon.h>
#include <BF_Special_Util/Special_Util.h>
#include <SpecialConstants/SpecialConstants.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <MoveTable/MoveTable.h>
#include <stdio.h>
#include <stdlib.h>

void ConsolePrintEntireEntryFile(char *fileName);
//void FilePrintEntireEntryFile(char *fileName, char *outputFileName); //TODO:define
//pokemon data into entry
void BaseStatsToEntry(PokemonEntry *pEntry);
void BaseStatsArrayFromName(char *name, unsigned int name_limit, unsigned int *statArray, unsigned int statArrayLimit);


void BaseStatsFileToArray(FILE *fptr, unsigned int *statArray, unsigned int statArrayLimit);
void EVLineToArray(char *EVLine, unsigned int line_limit, unsigned int *EVTable);


//entry specific data into entry
void DataWithoutRegionToEntry(PokemonEntry *pEntry,unsigned int choice,unsigned int IV, unsigned int level);
void DataToEntry(PokemonEntry *pEntry,unsigned int region, unsigned int choice,unsigned int IV, unsigned int level);

//fast-forward fin Pointer to point to the correct entry choice in the file.
void GoToEntryChoice(FILE *fin, unsigned int choice);

//converting line to data to put into entry. Then put into entry.
void TypeLineToEntry(char *typeLine,PokemonEntry *pEntry);
void MoveLineToEntry(char *moveLine, PokemonEntry *pEntry, unsigned int choice);
void NatureLineToEntry(char *natureLine, unsigned int line_limit,PokemonEntry *pEntry);




void RefinedStatsToEntry(unsigned int *EVTable, unsigned int IV, unsigned int level, char *natureLine, unsigned int line_limit, PokemonEntry *pEntry);


//Public calls. Either making a new entry, or modifying an already existing entry structure to contain different data
PokemonEntry *NewEntryFromNameChoice(char *name, unsigned int choice);
PokemonEntry *NewEntryFromData(char *name, unsigned int region, unsigned int choice, unsigned int IV, unsigned int level);
void SetEntryFromNameChoice(PokemonEntry *entry, char *name, unsigned int choice);
void SetEntryFromData(PokemonEntry *entry, char *name, unsigned int region, unsigned int choice, unsigned int IV, unsigned int level);

void ConsolePrintEntryList(char *name,unsigned int region) {
	char fileName[MAX_FILE_NAME] = ENTRY_DIRECTORY;
	AppendRegionToString(region,fileName,MAX_FILE_NAME);
	AppendArrayToArray(name,MAX_NAME,fileName,MAX_FILE_NAME);
	ConsolePrintEntireEntryFile(fileName);
}

void ConsolePrintForPokemon(char *name) {
	char fileName[MAX_FILE_NAME] = ENTRY_DIRECTORY;	
	CorrectRegionPrompt(fileName, MAX_FILE_NAME);
	AppendArrayToArray(name,MAX_NAME,fileName,MAX_FILE_NAME);
	ConsolePrintEntireEntryFile(fileName);
	
}

void ConsolePrintEntireEntryFile(char *fileName) {
	FILE *fin = fopen(fileName,"r");
	if(fin == 0) {
		printf("FILE OPEN of %s failed\n", fileName);
		GlobalDestroyer(1,0,0);
	}
	unsigned int flag = 0;
	unsigned int moveNum[1] = {0};
	char line[MAX_LINE_LENGTH] = {0};
	while( fgets(line,MAX_LINE_LENGTH - 5,fin) != 0) {
		
		flag = StringToUnsignedInt(line,MAX_LINE_LENGTH,moveNum);
		if(flag == 0 && moveNum[0] != 0) 
			GetMoveNameFromID(moveNum[0], line, MAX_LINE_LENGTH);
		printf("%s",line);
	}

}


void GoToEntryChoice(FILE *fin, unsigned int choice) {
	unsigned int i = 0;
	char line[MAX_LINE_LENGTH] = {0};
	for(i = 0; i < choice; i++) {
		while( line[0] != '\n')
			if(fgets(line,MAX_LINE_LENGTH - 5, fin) == 0)
				GlobalDestroyer(1,0,0);
	}
}


void TypeLineToEntry(char *typeLine,PokemonEntry *pEntry) {

	unsigned int i = 0;
	unsigned int hasTwoTypes = 0;
	for(i = 0; typeLine[0] != 0 && i < MAX_LINE_LENGTH; i++)
		if( typeLine[i] == '/') {
			hasTwoTypes = 1;
			i += 1;
			break; }
		
	Type t1 = TokenToType(typeLine);
	Type t2 = NONE;
	if( hasTwoTypes == 1) {
		t2 = TokenToType(typeLine + i);
	}
	pEntry->SetPrimaryType(pEntry,t1);
	pEntry->SetSecondaryType(pEntry,t2);
} 

void MoveLineToEntry(char *moveLine, PokemonEntry *pEntry, unsigned int choice) {

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


void NatureLineToEntry(char *natureLine, unsigned int line_limit, PokemonEntry *pEntry) {

	typedef enum Nature{ HARDY, LONELY, BRAVE, ADAMANT, NAUGHTY, BOLD, DOCILE, RELAXED, IMPISH, LAX, TIMID, 
	HASTY, SERIOUS, JOLLY, NAIVE, MODEST, MILD, QUIET, BASHFUL, RASH, CALM, GENTLE, SASSY, CAREFUL, QUIRKY } Nature;

	typedef enum Stats{ HP, A, D, SA, SD, S} Stats;

	static char mod[NUM_OF_NATURES][NUM_OF_STATS];
	static unsigned int flag = 0;
	unsigned int i,j;
	if(flag == 0) {


	for(i = 0; i < NUM_OF_NATURES; i++)
		for(j = 0; j < NUM_OF_STATS; j++)
			mod[i][j] = 1;

	mod[LONELY][A] = 2;
	mod[LONELY][D] = 0;
	mod[BRAVE][A] = 2;
	mod[BRAVE][S] = 0;
	mod[ADAMANT][A] = 2;
	mod[ADAMANT][SA] = 0;
	mod[NAUGHTY][A] = 2;
	mod[NAUGHTY][SD] = 0;

	mod[BOLD][D] = 2;
	mod[BOLD][A] = 0;
	mod[RELAXED][D] = 2;
	mod[RELAXED][S] = 0;
	mod[IMPISH][D] = 2;
	mod[IMPISH][SA] = 0;
	mod[LAX][D] = 2;
	mod[LAX][SD] = 0;

	mod[TIMID][S] = 2;
	mod[TIMID][A] = 0;
	mod[HASTY][S] = 2;
	mod[HASTY][D] = 0;
	mod[JOLLY][S] = 2;
	mod[JOLLY][SA] = 0;
	mod[NAIVE][S] = 2;
	mod[NAIVE][SD] = 0;
	
	mod[MODEST][SA] = 2;
	mod[MODEST][A] = 0;
	mod[MILD][SA] = 2;
	mod[MILD][D] = 0;
	mod[QUIET][SA] = 2;
	mod[QUIET][S] = 0;
	mod[RASH][SA] = 2;
	mod[RASH][SD] = 0;

	mod[CALM][SD] = 2;
	mod[CALM][A] = 0;
	mod[GENTLE][SD] = 2;
	mod[GENTLE][D] = 0;
	mod[SASSY][SD] = 2;
	mod[SASSY][S] = 0;
	mod[CAREFUL][SD] = 2;
	mod[CAREFUL][SA] = 0; 
	flag = 1; }

	Nature entryNat = HARDY; //used for initialization. okay since hardy doesnt affect stats

	switch(natureLine[0]) {
		case 'A':
			entryNat = ADAMANT; break;
		case 'B':
			switch(natureLine[1]) {
				case 'a': entryNat = BASHFUL; break;
				case 'o': entryNat = BOLD; break;
				case 'r': entryNat = BRAVE; break;
			} break;
		case 'C':
			switch(natureLine[2]) {
				case 'l': entryNat = CALM; break;
				case 'r': entryNat = CAREFUL; break;
			} break;
		case 'D':
			entryNat = DOCILE; break;
		case 'G':
			entryNat = GENTLE; break;
		case 'H':
			switch(natureLine[2]) {
				case 'r': entryNat = HARDY; break;
				case 's': entryNat = HASTY; break;
			} break;
		case 'I':
			entryNat = IMPISH; break;
			//impish
		case 'J':
			entryNat = JOLLY; break;
			//jolly
		case 'L': 
			switch(natureLine[1]) {
				case 'a': entryNat = LAX; break;
				case 'o': entryNat = LONELY; break; 
			} break;
		case 'M':
			switch(natureLine[1]) {
				case 'i': entryNat = MILD; break;
				case 'o': entryNat = MODEST; break;
			}
			//modest,mild
		case 'N':
			switch(natureLine[2]) {
				case 'i': entryNat = NAIVE; break;
				case 'u': entryNat = NAUGHTY; break;
			} break;
			//naughty, naive
		case 'Q':
			switch(natureLine[3]) {
				case 'e': entryNat = QUIET; break;
				case 'r': entryNat = QUIRKY; break;
			} break;
			//quiet quirky
		case 'R':
			switch(natureLine[1]) {
				case 'a': entryNat = RASH; break;
				case 'e': entryNat = RELAXED; break;
			} break;
			//relaxed,rash
		case 'S':
			switch(natureLine[1]) {
				case 'a': entryNat = SASSY; break;	
				case 'e': entryNat = SERIOUS; break;
			} break;
			//serious,sassy
		case 'T':
			entryNat = TIMID; break;
			//timid
	}

//	printf("Nature is %u\n",entryNat);
	
	unsigned int augStats[NUM_OF_STATS] = {0};
	augStats[HP] = pEntry->GetHitPoints(pEntry);
	augStats[A] = pEntry->GetAttack(pEntry);
	augStats[D] = pEntry->GetDefense(pEntry);
	augStats[SA] = pEntry->GetSpecialAttack(pEntry);
	augStats[SD] = pEntry->GetSpecialDefense(pEntry);
	augStats[S] = pEntry->GetSpeed(pEntry);

	i = 0;
	for(j = 0; j < NUM_OF_STATS; j++) 
		if(mod[entryNat][j] == 2) {
			augStats[j] += (augStats[j] / 10);
		}
		if(mod[entryNat][j] == 0) {
			augStats[j] -= (augStats[j] / 10);
		} 

	pEntry->SetHitPoints(pEntry, augStats[HP]);
	pEntry->SetAttack(pEntry, augStats[A]);
	pEntry->SetDefense(pEntry, augStats[D]);
	pEntry->SetSpecialAttack(pEntry, augStats[SA]);
	pEntry->SetSpecialDefense(pEntry, augStats[SD]);
	pEntry->SetSpeed(pEntry, augStats[S]);
	

}

void EVLineToArray(char *EVLine, unsigned int line_limit, unsigned int *EVTable) {
	char num[MAX_NAME] = {0};
	int i;
	for(i = 0;i < line_limit && i < MAX_NAME && EVLine[i] >= '0' && EVLine[i] <= '9'; i++)
		num[i] = EVLine[i];

	while( EVLine[i] < 'A' || EVLine[i] > 'Z')
		i++;

//	printf("%s\n", num);

	switch(EVLine[i]) {
		case 'A': 	StringToUnsignedInt(num, MAX_NAME, (EVTable + 1) ); 
				break;
		case 'D':	StringToUnsignedInt(num, MAX_NAME, (EVTable + 2) ); 
				break;

		case 'H':	StringToUnsignedInt(num, MAX_NAME, EVTable);
				break;
		
		case 'S':
			switch(EVLine[i + 1]) {
				case 'A':	StringToUnsignedInt(num, MAX_NAME, (EVTable + 3) ); 
						break;
				case 'D':	StringToUnsignedInt(num, MAX_NAME, (EVTable + 4) );
						break;
				case 'p':	StringToUnsignedInt(num, MAX_NAME, (EVTable + 5) );
						break; 
			} 		

	}

//	for(i = 0; i < 6; i++)
//		printf("EVS are %u\n",EVTable[i]);


}

void RefinedStatsToEntry(unsigned int *EVTable, unsigned int IV, unsigned int level, char *natureLine, unsigned int line_limit, PokemonEntry *pEntry) {
	unsigned int hitPoints,attack, defense, specialAttack, specialDefense, speed;
	hitPoints = CalcHPStat( pEntry->GetHitPoints(pEntry), EVTable[0], IV, level);

	attack = CalcNonHPStat( pEntry->GetAttack(pEntry), EVTable[1], IV, level);
	defense = CalcNonHPStat( pEntry->GetDefense(pEntry), EVTable[2], IV, level);
	specialAttack = CalcNonHPStat( pEntry->GetSpecialAttack(pEntry), EVTable[3], IV, level);
	specialDefense = CalcNonHPStat( pEntry->GetSpecialDefense(pEntry), EVTable[4], IV, level);
	speed = CalcNonHPStat( pEntry->GetSpeed(pEntry), EVTable[5], IV, level);

	pEntry->SetHitPoints(pEntry, hitPoints);
	pEntry->SetAttack(pEntry, attack);
	pEntry->SetDefense(pEntry, defense);
	pEntry->SetSpecialAttack(pEntry, specialAttack);
	pEntry->SetSpecialDefense(pEntry, specialDefense);
	pEntry->SetSpeed(pEntry, speed);

	NatureLineToEntry(natureLine, line_limit, pEntry);
}

//Augments the pokemonEntry based on which selection was made. 0,1,2,3
void DataWithoutRegionToEntry(PokemonEntry *pEntry,unsigned int choice,unsigned int IV, unsigned int level) {


//	printf("Start of DataToEntry\n");
	pEntry->SetLevel(pEntry,level);
	char entryFileName[MAX_FILE_NAME] = ENTRY_DIRECTORY;
	char name[MAX_NAME] = {0};
	pEntry->GetName(pEntry,name,MAX_NAME);
	CorrectRegionPrompt(entryFileName, MAX_FILE_NAME);
	AppendArrayToArray(name, MAX_NAME, entryFileName, MAX_FILE_NAME);

	FILE *fin = fopen(entryFileName,"r");
	if(fin == 0) {
		GlobalDestroyer(1,0,0);
	}

//	printf("After data entry file open section\n");
	//move file pointer to correct position in file, then parse data
	GoToEntryChoice(fin,choice);
	char typeLine[MAX_LINE_LENGTH] = {0};
	char moveLine[MAX_LINE_LENGTH] = {0};
	char itemLine[MAX_LINE_LENGTH] = {0};
	char natureLine[MAX_LINE_LENGTH] = {0};
	char EVLine[MAX_LINE_LENGTH] = {0};
	SafeReadLine(typeLine,MAX_LINE_LENGTH, fin,1);
	TypeLineToEntry(typeLine,pEntry);

	int i = 0;
	while( i < MAX_NUM_MOVES) {
		SafeReadLine(moveLine,MAX_LINE_LENGTH - 5, fin,1);
		MoveLineToEntry(moveLine,pEntry,i);
		i++;
	}

	SafeReadLine(itemLine,MAX_LINE_LENGTH,fin,1);
	SafeReadLine(natureLine,MAX_LINE_LENGTH,fin,1);

	i = 0;
	unsigned int EVTable[NUM_OF_STATS] = {0};
	SafeReadLine(EVLine,MAX_NAME, fin, 1);
	while( EVLine[0] != '\n') {
		EVLineToArray(EVLine, MAX_LINE_LENGTH,EVTable);
		SafeReadLine(EVLine,MAX_LINE_LENGTH, fin, 1);

	}
	

	RefinedStatsToEntry(EVTable, IV, level, natureLine,MAX_LINE_LENGTH, pEntry);
	fclose(fin);

//	printf("After close data entry file section\n");
}

//Augments the pokemonEntry based on which selection was made. 0,1,2,3
void DataToEntry(PokemonEntry *pEntry, unsigned int region, unsigned int choice,unsigned int IV, unsigned int level) {


//	printf("Start of DataToEntry\n");
	pEntry->SetLevel(pEntry,level);
	char entryFileName[MAX_FILE_NAME] = ENTRY_DIRECTORY;
	char name[MAX_NAME] = {0};
	pEntry->GetName(pEntry,name,MAX_NAME);
	AppendRegionToString(region,entryFileName,MAX_FILE_NAME); //ENTRY_DIRECTORY/REGION_SUB_DIR
	AppendArrayToArray(name, MAX_NAME, entryFileName, MAX_FILE_NAME); //ENTRY_DIRECTION/REGION_SUB_DIR/NAME

	FILE *fin = fopen(entryFileName,"r");
	if(fin == 0) {
		GlobalDestroyer(1,0,0);
	}

//	printf("After data entry file open section\n");
	//move file pointer to correct position in file, then parse data
	GoToEntryChoice(fin,choice);
	char typeLine[MAX_LINE_LENGTH] = {0};
	char moveLine[MAX_LINE_LENGTH] = {0};
	char itemLine[MAX_LINE_LENGTH] = {0};
	char natureLine[MAX_LINE_LENGTH] = {0};
	char EVLine[MAX_LINE_LENGTH] = {0};
	SafeReadLine(typeLine,MAX_LINE_LENGTH, fin,1);
	TypeLineToEntry(typeLine,pEntry);

	int i = 0;
	while( i < MAX_NUM_MOVES) {
		SafeReadLine(moveLine,MAX_LINE_LENGTH - 5, fin,1);
		MoveLineToEntry(moveLine,pEntry,i);
		i++;
	}

	SafeReadLine(itemLine,MAX_LINE_LENGTH,fin,1);
	SafeReadLine(natureLine,MAX_LINE_LENGTH,fin,1);

	i = 0;
	unsigned int EVTable[NUM_OF_STATS] = {0};
	SafeReadLine(EVLine,MAX_NAME, fin, 1);
	while( EVLine[0] != '\n') {
		EVLineToArray(EVLine, MAX_LINE_LENGTH,EVTable);
		SafeReadLine(EVLine,MAX_LINE_LENGTH, fin, 1);

	}
	

	RefinedStatsToEntry(EVTable, IV, level, natureLine,MAX_LINE_LENGTH, pEntry);
	fclose(fin);

//	printf("After close data entry file section\n");
}


// the file should have each stat on a different line, statName statAmount 
void BaseStatsFileToArray(FILE *fptr, unsigned int *statArray, unsigned int statArrayLimit) {

	unsigned int i = 0; //array offset
	char buffer[MAX_LINE_LENGTH] = {0};

	while(i < statArrayLimit && fgets(buffer, MAX_LINE_LENGTH, fptr) != 0) {

		StringToUnsignedInt(buffer, MAX_LINE_LENGTH, (statArray + i) );
		//add Logger function to indicate failure. 
		i++;
	}

}




void BaseStatsArrayFromName(char *name, unsigned int name_limit, unsigned int *statArray, unsigned int statArrayLimit) {
	char fileName[MAX_FILE_NAME] = BASE_STATS_DIR;
	AppendArrayToArray(name, name_limit, fileName, MAX_FILE_NAME);
	
	//printf("base stat file name is %s\n", fileName);

	FILE *fin = fopen(fileName, "r");
	if(fin == 0) {
		GlobalDestroyer(1,0,0);
	}
	//Extracts base stats out of file and put into array.
	BaseStatsFileToArray(fin, statArray, statArrayLimit);
	fclose(fin);

	//printf("Close base stat file %s\n",fileName);
}



void BaseStatsToEntry(PokemonEntry *pEntry) {
	char name[MAX_NAME] = {0};
	pEntry->GetName(pEntry,name,MAX_NAME);
	unsigned int statTable[NUM_OF_STATS];
	BaseStatsArrayFromName(name, MAX_NAME, statTable, NUM_OF_STATS);

	pEntry->SetHitPoints(pEntry, statTable[0]);
	pEntry->SetAttack(pEntry, statTable[1]);
	pEntry->SetDefense(pEntry, statTable[2]);
	pEntry->SetSpecialAttack(pEntry, statTable[3]);
	pEntry->SetSpecialDefense(pEntry, statTable[4]);
	pEntry->SetSpeed(pEntry, statTable[5]);	
		
}


/*	1/4/15 Currently, setup so that prints the pokemon entries created from each of the four entries,
	using the entry data + zero IV's and level 100. due to being easy to use high level functions.
	WARNING: not known actually how many entries are in the file, so IT WILL FAIL for entry files with < 4.
	TODO: Change it to something better, like literally printing out the entry file with actual move names
	instead of just the numbers.
**/
/*
void ConsolePrintEntireEntryFile(char *name) {
	PokemonEntry *pEntry = NewEntryFromNameChoice(name,0);
	pEntry->ConsolePrint(pEntry);
	unsigned int i = 1;
	for(i = 1; i <= 3; i++) {
	SetEntryFromNameChoice(pEntry,name,1);
	pEntry->ConsolePrint(pEntry); }
}'*/

PokemonEntry *NewEntryFromNameChoice(char *name, unsigned int choice) {
	PokemonEntry *pEntry = NewPokemonEntry();
	pEntry->SetName(pEntry, name);

	BaseStatsToEntry(pEntry);
	DataWithoutRegionToEntry(pEntry,choice,0,100);

	return pEntry;

}

PokemonEntry *NewEntryFromData(char *name, unsigned int region, unsigned int choice, unsigned int IV, unsigned int level) {
	PokemonEntry *pEntry = NewPokemonEntry();
	pEntry->SetName(pEntry, name);

	BaseStatsToEntry(pEntry);
	DataToEntry(pEntry,region,choice,IV,level);

	return pEntry;
}

void SetEntryFromNameChoice(PokemonEntry *pEntry, char *name, unsigned int choice) {
	pEntry->SetName(pEntry, name);

	BaseStatsToEntry(pEntry);
	DataWithoutRegionToEntry(pEntry,choice,0,100);
}


void SetEntryFromData(PokemonEntry *pEntry, char *name,  unsigned int region, unsigned int choice, unsigned int IV, unsigned int level) {
	pEntry->SetName(pEntry, name);

	BaseStatsToEntry(pEntry);
	DataToEntry(pEntry,region,choice,IV,level);
}




