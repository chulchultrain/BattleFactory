#include <RetrieveData/RetrievePokemon.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <SpecialConstants/SpecialConstants.h>
#include <BattleSimulation/BattleSimulation.h>
#include <BF_Special_Util/Special_Util.h>
#include <PokemonEntry/PokemonEntry.h>
#include <EntryOptions/EntryOptions.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct MoveDamage {

char name[MAX_NAME];
unsigned int damage;

} MoveDamage;

struct BattleSimPrivate{
	PokemonEntry *entry1;
	PokemonEntry *entry2;
	char entry1Name[MAX_NAME];
	char entry2Name[MAX_NAME];
	MoveDamage damages[MAX_NUM_MOVES * 2]; //damages[0-MAX_NUM_MOVES) for entry 1 to 2. damages[MAX_NUM_MOVES-) entry 2 to 1
};

//create
void SetBattleSimFunctionPointers(BattleSim *obj);
void SetBattleSimMemory(BattleSimPrivate *memPtr);

//initialize choices. be sure to change in header file the comments.
void BattleSimInitializationConsoleInput(BattleSim *obj);
void BattleSimInitializationFileInput(BattleSim *obj, char *fileName);
void BattleSimInitializationEntries(BattleSim *obj, PokemonEntry *e1, PokemonEntry *e2);

//simulate
unsigned int calcMoveDamage(PokemonEntry *attacker, PokemonEntry *defender, unsigned int moveChoice);
void BattleSimSimulate(BattleSim *original);

//print
void ConsolePrintMoveDamage(MoveDamage md);
void FilePrintMoveDamage(MoveDamage md, FILE *fout);
void BattleSimConsolePrint(BattleSim *obj);
void BattleSimFilePrint(BattleSim *obj, char *fileName);

void BattleSimMenu() {
	EntryOptions option1 = DefaultOptions(0,0), option2 = DefaultOptions(0,0);
	char buffer[MAX_LINE_LENGTH] = {0};
	unsigned int choice = 0, innerChoice = 0,temp = 0, numEntryChoices = 0;
	printf("To display choices, enter 1\n");
	EntryOptions *cEntry = 0;
	do {
		SafeReadLine(buffer,MAX_LINE_LENGTH,stdin,1);
		if(!StringToUnsignedInt(buffer,MAX_LINE_LENGTH,&choice) ) {
			choice = 1;
			continue;
		}
		switch(choice) {
			case 0: //just exit
				break;
			case 1: //display choices
				printf("0 - exit\n");
				printf("1 - display choices\n");
				printf("2 - display both entries\n");
				printf("3 - set entry 1 name\n");
				printf("4 - set entry 1 region\n");
				printf("5 - set entry 1 IV\n");
				printf("6 - set entry 1 level\n");
				printf("7 - set entry 2 name\n");
				printf("8 - set entry 2 region\n");
				printf("9 - set entry 2 IV\n");
				printf("10 - set entry 2 level\n");
			case 2: //display both entries
				ConsolePrintOptions(option1);
				printf("\n");
				ConsolePrintOptions(option2);
				printf("\n");
			case 3: //display entryfile for entry 1 
				ConsolePrintEntryList(option1.name,option1.region);					
			case 4: //display entryfile for entry 2	
				ConsolePrintEntryList(option2.name,option2.region);	
			case 5: //set entry 1 something
				cEntry = &option1;
				break;
			case 6: //set entry 2 something
				cEntry = &option2;
				break;
		}
		if(choice == 5 || choice == 6) {
				
			SafeReadLine(buffer,MAX_LINE_LENGTH,stdin,1);
			if(!StringToUnsignedInt(buffer,MAX_LINE_LENGTH,&innerChoice) ) {
				innerChoice = 0;
			continue;
			}
			switch(innerChoice) {
				case 1: //entry name
					SafeReadLineRNL(cEntry->name,MAX_NAME,stdin,1);
					cEntry->choice = 0;
					break;			
				case 2: //entry region
					SafeReadLine(buffer,MAX_LINE_LENGTH,stdin,1);
					if(StringToUnsignedInt(buffer,MAX_LINE_LENGTH,&temp)) {
						printf("Invalid region. Should be non-negative int less than %u\n",MAX_REGIONS);
					}
					else {
						if(temp >= 0 && temp < MAX_REGIONS) {
							cEntry->region = temp;
						} 
						else
							printf("Invalid region. Should be non-negative int less than %u\n",MAX_REGIONS);
					}
					break;
				case 3: //entry choice
			//		numEntryChoices = SizeEntryList(EntryOptions options); //TODO:IMPLEMENET THIS
					numEntryChoices = 4;
					SafeReadLine(buffer,MAX_LINE_LENGTH,stdin,1);
					if(StringToUnsignedInt(buffer,MAX_LINE_LENGTH,&temp)) {
						printf("Invalid choice. Should be non-negative int less than %u\n",numEntryChoices);
					}	
					else {
						if(temp >= 0 && temp < numEntryChoices)
							cEntry->choice = temp;
						else
							printf("Invalid choice. Should be non-negative int less than %u\n",numEntryChoices);
					}
					break;									
				case 4: //entry IV
					SafeReadLine(buffer,MAX_LINE_LENGTH,stdin,1);
					if(StringToUnsignedInt(buffer,MAX_LINE_LENGTH,&temp)) {
						printf("Invalid IV\n");
					}
					else {
						cEntry->IV = temp;
					}
					break;
				case 5: //entry level
					SafeReadLine(buffer,MAX_LINE_LENGTH,stdin,1);
					if(StringToUnsignedInt(buffer,MAX_LINE_LENGTH,&temp)) {
						printf("Invalid level\n");
					}
					else {
						cEntry->level = temp;
					}
					break;					
					

				default:
					printf("Invalid Choice. Option set failed.\n");
			}				
			
		}
	} while(choice != 0);
}

//clean data
void WipeBattleSimData(BattleSim *obj);



void SetBattleSimMemory(BattleSimPrivate *memPtr) {
	memPtr->entry1 = memPtr->entry2 = 0;
	memPtr->entry1Name[0] = memPtr->entry2Name[0] = 0;
	unsigned int i;
	for(i = 0; i < MAX_NUM_MOVES * 2; i++) {
		memPtr->damages[i].damage = 0;
		memPtr->damages[i].name[0] = 0;
	}
}

void SetBattleSimFunctionPointers(BattleSim *obj) {
	obj->ConsoleInput = BattleSimInitializationConsoleInput;
	obj->FileInput = BattleSimInitializationFileInput;
	obj->Simulate = BattleSimSimulate;
	obj->ConsolePrint = BattleSimConsolePrint;
	obj->FilePrint = BattleSimFilePrint;
	obj->Purge = WipeBattleSimData;
	obj->Menu = BattleSimMenu;
}

BattleSim *NewBattleSim() {

	BattleSim *result = malloc(sizeof(BattleSim));

	if(result == 0) {
		GlobalDestroyer(1,0,0);
	}
	result->mem = 0;

	GlobalDestroyer(0,result,BATTLESIMULATION);

	result->mem = malloc(sizeof(BattleSimPrivate));

	if(result->mem == 0) {
		GlobalDestroyer(1,0,0);
	}
	SetBattleSimMemory(result->mem);
	SetBattleSimFunctionPointers(result);

	return result;
}

void WipeBattleSimData(BattleSim *obj) {
	if(obj != 0) {
		if(obj->mem->entry1 != 0) {
			DeletePokemonEntry(obj->mem->entry1);
			obj->mem->entry1 = 0; }
		
		if(obj->mem->entry2 != 0) {
			DeletePokemonEntry(obj->mem->entry2);
			obj->mem->entry2 = 0; }
		
	}
}

void DeleteBattleSim(BattleSim *obj) {
	if(obj != 0) {
		GlobalDestroyer(2,obj,BATTLESIMULATION);
		if(obj->mem != 0) {
			free(obj->mem);
			obj->mem = 0;
		}
		free(obj);
	}
}

//initialization with entries already made
void BattleSimInitializationEntries(BattleSim *obj, PokemonEntry *e1, PokemonEntry *e2) {
	obj->mem->entry1 = e1;
	obj->mem->entry2 = e2;
}

void BattleSimInitializationFileInput(BattleSim *obj, char *fileName) {
	FILE *fin = fopen(fileName, "r");
	if(fin == 0) 
		GlobalDestroyer(1,0,0);

	char name1[MAX_NAME] = {0};
	char name2[MAX_NAME] = {0};
	char buffer[MAX_LINE_LENGTH] = {0};
	unsigned int region[1] = {0};
	unsigned int choice1[1] = {0};
	unsigned int choice2[1] = {0};
	unsigned int IV[1] = {0};
	unsigned int level = 100;

	//region
	RegionFromFileInput(region, fin);
	//entry1	
	SafeReadLineRNL(name1,MAX_LINE_LENGTH,fin,1);	
	SafeReadLineRNL(buffer,MAX_LINE_LENGTH,fin,1);
	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,choice1);	
	//entry2
	SafeReadLineRNL(name2, MAX_NAME,fin,1); 
	SafeReadLineRNL(buffer,MAX_LINE_LENGTH,fin,1);
	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,choice2);
	//IVs
	SafeReadLineRNL(buffer,MAX_LINE_LENGTH,fin,1);	
	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,IV);


	EntryOptions options1,options2;
	copyName(name1,options1.name);	
	copyName(name2,options2.name);

	options1.region = options2.region = region[0];
	options1.choice = choice1[0];
	options2.choice = choice2[0];

	options1.IV = options2.IV = IV[0];
	options1.level = options2.level = level;
	
	
	
	PokemonEntry *entry1 = NewEntryFromData(options1);
	PokemonEntry *entry2 = NewEntryFromData(options2);

	obj->Purge(obj);
	obj->mem->entry1 = entry1;
	obj->mem->entry2 = entry2;
	fclose(fin);
}


//easy way to just from stdin
void BattleSimInitializationConsoleInput(BattleSim *obj) {

	char name1[MAX_NAME] = {0};
	char name2[MAX_NAME] = {0};

	char buffer[MAX_LINE_LENGTH] = {0};
	unsigned int region[1] = {0};
	unsigned int choice1[1] = {0};
	unsigned int choice2[1] = {0};
	unsigned int IV[1] = {0};
	unsigned int level = 100;

	RegionFromConsoleInput(region);

	printf("Entry name of first pokemon of entry: ");
	SafeReadLineRNL(name1, MAX_NAME,stdin,1); 

	//ConsolePrintEntryFile(

	ConsolePrintEntryList(name1,region[0]);

	printf("Entry choice of first pokemon: ");
	SafeReadLineRNL(buffer,MAX_LINE_LENGTH,stdin,1);


	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,choice1);

	printf("Entry name of second pokemon of entry: ");
	SafeReadLineRNL(name2, MAX_NAME,stdin,1); 
	ConsolePrintEntryList(name2,region[0]);

	printf("Entry choice of second pokemon: ");
	SafeReadLineRNL(buffer,MAX_LINE_LENGTH,stdin,1);	

	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,choice2);

	printf("Entry IVs of Pokemon");
	SafeReadLineRNL(buffer,MAX_LINE_LENGTH,stdin,1);	

	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,IV);

	EntryOptions options1,options2;
	copyName(name1,options1.name);	
	copyName(name2,options2.name);

	options1.region = options2.region = region[0];
	options1.choice = choice1[0];
	options2.choice = choice2[0];

	options1.IV = options2.IV = IV[0];
	options1.level = options2.level = level;
	
	PokemonEntry *entry1 = NewEntryFromData(options1);
	PokemonEntry *entry2 = NewEntryFromData(options2);


	obj->Purge(obj);
	obj->mem->entry1 = entry1;
	obj->mem->entry2 = entry2;
	
}


//TODO: Change to doubles
unsigned int calcMoveDamage(PokemonEntry *attacker, PokemonEntry *defender, unsigned int choice) {
	unsigned int base = 0;
	MoveCategory cat = EMPTY;
	Type t = NONE;
	unsigned int oStat = 0;
	unsigned int dStat = 0;
	double damage = 0;


	Type dType1 = defender->GetPrimaryType(defender);
	Type dType2 = defender->GetSecondaryType(defender);

	unsigned int level = attacker->GetLevel(attacker);

	base = attacker->GetMoveDamage(attacker,choice);
	cat = attacker->GetMoveCategory(attacker, choice);	
	t = attacker->GetMoveType(attacker, choice);
	
	switch(cat) {
		case EMPTY:
			return 0;
		case STATUS:
			return 0;
		case PHYSICAL:
			oStat = attacker->GetAttack(attacker);
			dStat = defender->GetDefense(defender);
			break;
		case SPECIAL:
			oStat = attacker->GetSpecialAttack(attacker);
			dStat = defender->GetSpecialDefense(defender);
			break;
			
	}
	
	damage = (2 * level + 10);

	damage *= (oStat * base);
	damage /= 250;
	damage /= dStat;
	damage += 2;
//	printf("damage is %f\n",damage);

	damage = ModDamageTypeResistance(damage,t, dType1);
	damage = ModDamageTypeResistance(damage,t, dType2);
//	printf("damage is %f\n",damage);

	//stab calculation
	if(t == attacker->GetPrimaryType(attacker) || t == attacker->GetSecondaryType(attacker) ) {
		damage +=  (damage / 2);
	}

//	printf("damage is %f\n",damage);
	
	return damage;

}

void BattleSimSimulate(BattleSim *original) {

	//printf("Reach start of simulate\n\n");

	PokemonEntry *entry1 = original->mem->entry1;
	PokemonEntry *entry2 = original->mem->entry2;

	MoveDamage *damages = original->mem->damages;

	entry1->GetName(entry1,original->mem->entry1Name,MAX_NAME);
	entry2->GetName(entry2,original->mem->entry2Name,MAX_NAME);

	unsigned int i = 0;
	for(i = 0; i < MAX_NUM_MOVES;i++)
		entry1->GetMoveName(entry1,i,damages[i].name, MAX_NAME);

	for(i = 0; i < MAX_NUM_MOVES; i++)
		entry2->GetMoveName(entry2,0,damages[MAX_NUM_MOVES + i].name, MAX_NAME);

	//entry1->ConsolePrint(entry1);
	//entry2->ConsolePrint(entry2);

	damages[0].damage = calcMoveDamage(entry1,entry2,0);
	damages[1].damage = calcMoveDamage(entry1,entry2,1);	
	damages[2].damage = calcMoveDamage(entry1,entry2,2);	
	damages[3].damage = calcMoveDamage(entry1,entry2,3);

	damages[4].damage = calcMoveDamage(entry2,entry1,0);
	damages[5].damage = calcMoveDamage(entry2,entry1,1);
	damages[6].damage = calcMoveDamage(entry2,entry1,2);
	damages[7].damage = calcMoveDamage(entry2,entry1,3);


}

void FilePrintMoveDamage(MoveDamage md, FILE *fout) {
	unsigned int upperBound = md.damage;
	unsigned int lowerBound = md.damage - (md.damage * 1.0 * 15 / 100); 
	fprintf(fout,"%s does between %u and %u\n", md.name, lowerBound,upperBound);
}

void ConsolePrintMoveDamage(MoveDamage md) {
	unsigned int upperBound = md.damage;
	unsigned int lowerBound = md.damage - (md.damage * 1.0 * 15 / 100); 
	printf("%s does between %u and %u\n", md.name, lowerBound,upperBound);
}

void BattleSimFilePrint(BattleSim *obj, char *fileName) {
	FILE *fout = fopen(fileName,"w");
	if( fout == 0) 
		GlobalDestroyer(1,0,0);

	char *entry1Name, *entry2Name;
	entry1Name = obj->mem->entry1Name;
	entry2Name = obj->mem->entry2Name;

	fprintf(fout,"%s moves to %s:\n",entry1Name, entry2Name);
	unsigned int i = 0;
	for(i = 0; i < MAX_NUM_MOVES; i++)
		FilePrintMoveDamage((obj->mem->damages)[i], fout);
	fprintf(fout,"\n");
	fprintf(fout,"%s moves to %s:\n",entry2Name, entry1Name);
	for(i = MAX_NUM_MOVES; i < 2 * MAX_NUM_MOVES;i++)
		FilePrintMoveDamage((obj->mem->damages)[i], fout);
}

void BattleSimConsolePrint(BattleSim *obj) {
	char *entry1Name, *entry2Name;
	entry1Name = obj->mem->entry1Name;
	entry2Name = obj->mem->entry2Name;

	printf("%s moves to %s:\n",entry1Name, entry2Name);
	unsigned int i = 0;
	for(i = 0; i < MAX_NUM_MOVES; i++)
		ConsolePrintMoveDamage((obj->mem->damages)[i]);
	printf("\n");
	printf("%s moves to %s:\n",entry2Name, entry1Name);
	for(i = MAX_NUM_MOVES; i < 2 * MAX_NUM_MOVES;i++)
		ConsolePrintMoveDamage((obj->mem->damages)[i]);
}


