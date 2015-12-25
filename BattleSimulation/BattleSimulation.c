#include <RetrieveData/RetrievePokemon.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <SpecialConstants/SpecialConstants.h>
#include <BattleSimulation/BattleSimulation.h>
#include <BF_Special_Util/Special_Util.h>
#include <PokemonEntry/PokemonEntry.h>
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

unsigned int calcMoveDamage(PokemonEntry *attacker, PokemonEntry *defender, unsigned int moveChoice);
void BattleSimSimulate(BattleSim *original);
void ConsolePrintMoveDamage(MoveDamage md);
void BattleSimConsolePrint(BattleSim *obj);

void SetBattleSimFunctionPointers(BattleSim *obj);
void SetBattleSimMemory(BattleSimPrivate *memPtr);

void BattleSimInitialization(BattleSim *obj);


void BattleSimCalcAllDamage(BattleSim *original);
void BattleSimConsolePrint(BattleSim *obj);


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
	obj->Initialize = BattleSimInitialization;
	obj->Simulate = BattleSimSimulate;
	obj->ConsolePrint = BattleSimConsolePrint;
	
}

BattleSim *NewBattleSim() {

	BattleSim *result = malloc(sizeof(BattleSim));

	if(result == 0) {
		GlobalDestroyer(1,0,0);
	}

	GlobalDestroyer(0,result,BATTLESIMULATION);

	result->mem = malloc(sizeof(BattleSimPrivate));

	if(result->mem == 0) {
		GlobalDestroyer(1,0,0);
	}
	SetBattleSimMemory(result->mem);
	SetBattleSimFunctionPointers(result);

	return result;
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

//TODO: Change to doubles
unsigned int calcMoveDamage(PokemonEntry *attacker, PokemonEntry *defender, unsigned int moveChoice) {
	unsigned int base = 0;
	MoveCategory cat = EMPTY;
	Type t = NONE;
	unsigned int oStat = 0;
	unsigned int dStat = 0;
	double damage = 0;

	printf("Accessing dType1 and dType2\n\n");

	Type dType1 = defender->GetPrimaryType(defender);
	Type dType2 = defender->GetSecondaryType(defender);

	unsigned int level = attacker->GetLevel(attacker);
	
	switch(moveChoice) {

		case 0:
			base = attacker->GetFirstMoveDamage(attacker);
			cat = attacker->GetFirstMoveCategory(attacker);	
			t = attacker->GetFirstMoveType(attacker);
			break;
		case 1:
			base = attacker->GetSecondMoveDamage(attacker);
			cat = attacker->GetSecondMoveCategory(attacker);	
			t = attacker->GetSecondMoveType(attacker);
			break;
		case 2:
			base = attacker->GetThirdMoveDamage(attacker);
			cat = attacker->GetThirdMoveCategory(attacker);	
			t = attacker->GetThirdMoveType(attacker);
			break;		
		case 3:
			base = attacker->GetFourthMoveDamage(attacker);
			cat = attacker->GetFourthMoveCategory(attacker);	
			t = attacker->GetFourthMoveType(attacker);
			break;
	}

	printf("right before get oStat and dStat\n\n");
	
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
	printf("damage is %f\n",damage);

	damage = ModDamageTypeResistance(damage,t, dType1);
	damage = ModDamageTypeResistance(damage,t, dType2);
	printf("damage is %f\n",damage);

	printf("right before stab\n\n");
	if(t == attacker->GetPrimaryType(attacker) || t == attacker->GetSecondaryType(attacker) ) {
		damage +=  (damage / 2);
	}

	printf("damage is %f\n",damage);
	
	return damage;

}


void BattleSimInitialization(BattleSim *obj) {
	char name1[MAX_NAME] = {0};
	char name2[MAX_NAME] = {0};

	char buffer[MAX_LINE_LENGTH] = {0};
	unsigned int choice1[1] = {0};
	unsigned int choice2[1] = {0};
	unsigned int IV[1] = {0};
	unsigned int level = 100;

	printf("Entry name of first pokemon of entry: ");
	SafeReadLineRNL(name1, MAX_NAME,stdin,1); 

	printf("Entry choice of first pokemon: ");
	SafeReadLineRNL(buffer,MAX_LINE_LENGTH,stdin,1);

	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,choice1);

	printf("Entry name of second pokemon of entry: ");
	SafeReadLineRNL(name2, MAX_NAME,stdin,1); 

	printf("Entry choice of second pokemon: ");
	fgets(buffer,MAX_LINE_LENGTH,stdin);	

	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,choice2);

	printf("Entry IVs of Pokemon");
	SafeReadLineRNL(buffer,MAX_LINE_LENGTH,stdin,1);	

	StringToUnsignedInt(buffer,MAX_LINE_LENGTH,IV);

	PokemonEntry *entry1 = NewEntryFromData(name1,choice1[0],IV[0],level);
	PokemonEntry *entry2 = NewEntryFromData(name2,choice2[0],IV[0],level);

	obj->mem->entry1 = entry1;
	obj->mem->entry2 = entry2;
	
}


void BattleSimSimulate(BattleSim *original) {

	printf("Reach start of simulate\n\n");

	PokemonEntry *entry1 = original->mem->entry1;
	PokemonEntry *entry2 = original->mem->entry2;

	MoveDamage *damages = original->mem->damages;

	entry1->GetName(entry1,original->mem->entry1Name,MAX_NAME);
	entry2->GetName(entry2,original->mem->entry2Name,MAX_NAME);

	entry1->GetFirstMoveName(entry1,damages[0].name, MAX_NAME);
	entry1->GetSecondMoveName(entry1,damages[1].name, MAX_NAME);
	entry1->GetThirdMoveName(entry1,damages[2].name, MAX_NAME);
	entry1->GetFourthMoveName(entry1,damages[3].name, MAX_NAME);

	entry2->GetFirstMoveName(entry2,damages[4].name, MAX_NAME);
	entry2->GetSecondMoveName(entry2,damages[5].name, MAX_NAME);
	entry2->GetThirdMoveName(entry2,damages[6].name, MAX_NAME);
	entry2->GetFourthMoveName(entry2,damages[7].name, MAX_NAME);

	entry1->ConsolePrint(entry1);
	entry2->ConsolePrint(entry2);

	printf("About to calculate move damage\n\n");
	damages[0].damage = calcMoveDamage(entry1,entry2,0);
	damages[1].damage = calcMoveDamage(entry1,entry2,1);	
	damages[2].damage = calcMoveDamage(entry1,entry2,2);	
	damages[3].damage = calcMoveDamage(entry1,entry2,3);

	damages[4].damage = calcMoveDamage(entry2,entry1,0);
	damages[5].damage = calcMoveDamage(entry2,entry1,1);
	damages[6].damage = calcMoveDamage(entry2,entry1,2);
	damages[7].damage = calcMoveDamage(entry2,entry1,3);

	printf("Reach end of simulate\n\n");
}

void ConsolePrintMoveDamage(MoveDamage md) {
	printf("%s does %u\n", md.name, md.damage);
}

void BattleSimConsolePrint(BattleSim *obj) {
	printf("%s moves:\n",obj->mem->entry1Name);
	unsigned int i = 0;
	for(i = 0; i < MAX_NUM_MOVES; i++)
		ConsolePrintMoveDamage((obj->mem->damages)[i]);
	printf("%s moves:\n",obj->mem->entry2Name);
	for(i = MAX_NUM_MOVES; i < 2 * MAX_NUM_MOVES;i++)
		ConsolePrintMoveDamage((obj->mem->damages)[i]);
}


