
#include <PokemonEntry/PokemonEntry.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdlib.h>
#include <stdio.h>
#include <PokemonEntry/Typing.h>
#include <PokemonEntry/PokemonStats.h>
#include <PokemonEntry/PokemonMoveSet.h>
#include <SpecialConstants/SpecialConstants.h>
#include <BF_Special_Util/Special_Util.h>

struct PokemonEntryPrivate {
	char name[MAX_NAME];
	TypeContainer *typeData;
	PokemonStats *pokeStats;
	PokemonMoveSet *moveSet;

//weaknesses/resistances/normal list
};




void SetPokemonName(PokemonEntry* original, const char* name);


void SetEntryL(PokemonEntry *original, unsigned int level);
void SetEntryHP(PokemonEntry* original, unsigned int HP);
void SetEntryA(PokemonEntry* original, unsigned int A);
void SetEntryD(PokemonEntry* original, unsigned int D);
void SetEntrySpA(PokemonEntry* original, unsigned int SpA);
void SetEntrySpD(PokemonEntry* original, unsigned int SpD);
void SetEntryS(PokemonEntry* original, unsigned int S);

void SetEntryPrimaryType(PokemonEntry* original, Type primary);
void SetEntrySecondaryType(PokemonEntry* original, Type secondary);


void SetEntryMove(PokemonEntry *original, unsigned int choice, char *move, unsigned int d, Type t, MoveCategory m);
void SetEntryMoveName(PokemonEntry *original, unsigned int choice, char *name);
void SetEntryMoveDamage(PokemonEntry *original, unsigned int choice, unsigned int damage);
void SetEntryMoveType(PokemonEntry *original, unsigned int choice, Type t);
void SetEntryMoveCategory(PokemonEntry *original, unsigned int choice, MoveCategory cat);


void GetEntryMoveName(PokemonEntry *original, unsigned int choice, char *dest, unsigned int limit);
unsigned int GetEntryMoveDamage(PokemonEntry *obj, unsigned int choice);
Type GetEntryMoveType(PokemonEntry *obj, unsigned int choice);
MoveCategory GetEntryMoveCategory(PokemonEntry *obj, unsigned int choice);
void GetEntryName(PokemonEntry *obj, char* dest, unsigned int limit);

unsigned int GetEntryL(PokemonEntry *obj);
unsigned int GetEntryHP(PokemonEntry *obj);
unsigned int GetEntryA(PokemonEntry *obj);
unsigned int GetEntryD(PokemonEntry *obj);
unsigned int GetEntrySpA(PokemonEntry *obj);
unsigned int GetEntrySpD(PokemonEntry *obj);
unsigned int GetEntryS(PokemonEntry *obj);

Type GetEntryPrimary(PokemonEntry* obj);

Type GetEntrySecondary(PokemonEntry* obj);


void PokemonEntryConsolePrint(PokemonEntry* obj);

void SetPokemonEntryFunctionPointers(PokemonEntry* original);

//TODO:NO MAGIC NUMBERS PLZ
//provide protection if longer than MAXNAME characters is entered.
//checked before this function If longer then end will be truncated.

/**
void SetPokemonEntryMemPointer(PokemonEntry *entryPtr) {
	if(entryPtr != 0)
		entryPtr->mem = 0;
}
**/
void SetPokemonEntryMemory(PokemonEntryPrivate *memPtr) {
	if(memPtr != 0) {
		memPtr->typeData = 0;
		memPtr->pokeStats = 0;
		memPtr->moveSet = 0;
		memPtr->name[0] = 0;
		memPtr->typeData = NewTypeContainer();
		memPtr->pokeStats = NewPokemonStats();
		memPtr->moveSet = NewPokemonMoveSet();
	}
}

PokemonEntry *NewPokemonEntry() {
	PokemonEntry *result = malloc(sizeof(PokemonEntry));
	if( result == 0)
		GlobalDestroyer(1,0,0);

	result->mem = 0;
	GlobalDestroyer(0,result,POKEMONENTRY);	

	result->mem = malloc(sizeof(PokemonEntryPrivate));
	if( result->mem == 0) {
		GlobalDestroyer(1,0,0);
	}
	SetPokemonEntryMemory(result->mem);
	SetPokemonEntryFunctionPointers(result);
	return result;

}


void ResetPokemonEntryData(PokemonEntry* recall) {
	//TODO:ADD CLEAR NAME
	if(recall->mem != 0) {
		int i;
		for(i = 0; i < MAX_NAME; i++)
			recall->mem->name[i] = 0;
	
		
		ResetPokemonStatsData(recall->mem->pokeStats);
		ResetTypeContainerData(recall->mem->typeData);
		/**
		//TODO:MAKE this function in PokmeonMoveSet
		ResetPokemonMoveSetData(recall->mem->moveSet);
		**/
	}
}


void ResetPokemonEntryAll(PokemonEntry* recall) {
	ResetPokemonEntryData(recall);
}

void DeletePokemonEntry(PokemonEntry* recall){
	//zero out name before free
	GlobalDestroyer(2,recall,POKEMONENTRY);
	if(recall != 0) {
		if(recall->mem != 0) {
			ResetPokemonEntryData(recall);
			if(recall->mem->pokeStats != 0) {
				DeletePokemonStats(recall->mem->pokeStats);
				recall->mem->pokeStats = 0; }
			if(recall->mem->typeData != 0) {
				DeleteTypeContainer(recall->mem->typeData);
				recall->mem->typeData = 0;
							}
			if(recall->mem->moveSet != 0) {
				DeletePokemonMoveSet(recall->mem->moveSet);
				recall->mem->moveSet = 0;
							}
			free(recall->mem);
			recall->mem = 0; }
		free(recall);
		 }
	//printf("Successful delete entry\n");
	
}



void SetPokemonName(PokemonEntry* original, const char* name) {	
	copyName(name, original->mem->name);
}



void SetPokemonEntryFunctionPointers(PokemonEntry* original) {
	original->SetName = SetPokemonName;
	original->SetLevel = SetEntryL;
	original->SetHitPoints = SetEntryHP;
	original->SetAttack = SetEntryA;
	original->SetDefense = SetEntryD;
	original->SetSpecialAttack = SetEntrySpA;
	original->SetSpecialDefense = SetEntrySpD;
	original->SetSpeed = SetEntryS;
	original->SetPrimaryType = SetEntryPrimaryType;
	original->SetSecondaryType = SetEntrySecondaryType;


	original->ConsolePrint = PokemonEntryConsolePrint;
	original->GetName = GetEntryName;
	original->GetLevel = GetEntryL;
	original->GetHitPoints = GetEntryHP;
	original->GetAttack = GetEntryA;
	original->GetDefense = GetEntryD;
	original->GetSpecialAttack = GetEntrySpA;
	original->GetSpecialDefense = GetEntrySpD;
	original->GetSpeed = GetEntryS;
	original->GetPrimaryType = GetEntryPrimary;
	original->GetSecondaryType = GetEntrySecondary;

	original->SetMove = SetEntryMove;
	original->SetMoveName = SetEntryMoveName;
	original->SetMoveDamage = SetEntryMoveDamage;
	original->SetMoveType = SetEntryMoveType;
	original->SetMoveCategory = SetEntryMoveCategory;

	original->GetMoveName = GetEntryMoveName;

	original->GetMoveDamage = GetEntryMoveDamage;

	original->GetMoveType = GetEntryMoveType;

	original->GetMoveCategory = GetEntryMoveCategory;

}

void SetEntryL(PokemonEntry* original, unsigned int level) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetL(statsPtr,level);
}

void SetEntryHP(PokemonEntry* original, unsigned int HP) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetHP(statsPtr, HP);
	
//	SetHitPoints(original->pokeStats, HP);
}

void SetEntryA(PokemonEntry* original, unsigned int A) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetA(statsPtr, A);
//	SetAttack(original->pokeStats, A);
}

void SetEntryD(PokemonEntry* original, unsigned int D) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetD(statsPtr, D);
//	SetDefense(original->pokeStats, D);
}

void SetEntrySpA(PokemonEntry* original, unsigned int SpA) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetSpA(statsPtr, SpA);
//	SetSpecialAttack(original->pokeStats, SpA);
}

void SetEntrySpD(PokemonEntry* original, unsigned int SpD) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetSpD(statsPtr, SpD);
//	SetSpecialDefense(original->pokeStats, SpD);
}

void SetEntryS(PokemonEntry* original, unsigned int S) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetS(statsPtr, S);
//	SetSpeed(original->pokeStats, S);
}

void SetEntryPrimaryType(PokemonEntry* original, Type primary) {
	TypeContainer *typePtr = original->mem->typeData;
	typePtr->SetPrimary(typePtr, primary);
//	SetPrimaryType(original->typeData, primary);
}

void SetEntrySecondaryType(PokemonEntry* original, Type secondary) {
	TypeContainer *typePtr = original->mem->typeData;
	typePtr->SetSecondary(typePtr, secondary);
//	SetSecondaryType(original->typeData, secondary);
}

void SetEntryMove(PokemonEntry *original, unsigned int choice, char *name, unsigned int damage, Type t, MoveCategory cat) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	moveSet->SetMoveName(moveSet,choice, name);
	moveSet->SetMoveDamage(moveSet,choice,damage);
	moveSet->SetMoveType(moveSet,choice,t);
	moveSet->SetMoveCategory(moveSet,choice,cat);

}

void SetEntryMoveName(PokemonEntry *original, unsigned int choice, char *name) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	moveSet->SetMoveName(moveSet, choice, name);
}

void SetEntryMoveDamage(PokemonEntry *original, unsigned int choice, unsigned int damage) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	moveSet->SetMoveDamage(moveSet,choice,damage);
}

void SetEntryMoveType(PokemonEntry *original, unsigned int choice, Type t) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	moveSet->SetMoveType(moveSet,choice,t);	
}

void SetEntryMoveCategory(PokemonEntry *original, unsigned int choice, MoveCategory cat) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	moveSet->SetMoveCategory(moveSet,choice,cat);
}

void GetEntryMoveName(PokemonEntry *original, unsigned int choice, char *move, unsigned int limit) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	moveSet->GetMoveName(moveSet, choice, move, limit);
}

unsigned int GetEntryMoveDamage(PokemonEntry *obj, unsigned int choice) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	return moveSet->GetMoveDamage(moveSet, choice);	
}


Type GetEntryMoveType(PokemonEntry *obj, unsigned int choice) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	return moveSet->GetMoveType(moveSet, choice);	
}


MoveCategory GetEntryMoveCategory(PokemonEntry *obj, unsigned int choice) {
	PokemonMoveSet *moveSet = original->mem->moveSet;
	return moveSet->GetMoveCategory(moveSet, choice);
}

void GetEntryName(PokemonEntry *obj, char* dest, unsigned int limit) {
	unsigned int i;
	unsigned int m = -1;
	if(limit > MAX_NAME)
		m = limit;
	else
		m = MAX_NAME;
	for(i = 0; i<m; i++) {
		dest[i] = obj->mem->name[i];
	}
}

unsigned int GetEntryL(PokemonEntry *obj) {
	PokemonStats *statsPtr = obj->mem->pokeStats;
	return statsPtr->GetL(statsPtr);
}

unsigned int GetEntryHP(PokemonEntry *obj) {
	PokemonStats *statsPtr = obj->mem->pokeStats;
	return statsPtr->GetHP(statsPtr);
}

unsigned int GetEntryA(PokemonEntry *obj) {
	PokemonStats *statsPtr = obj->mem->pokeStats;
	return statsPtr->GetA(statsPtr);
}

unsigned int GetEntryD(PokemonEntry *obj) {
	PokemonStats *statsPtr = obj->mem->pokeStats;
	return statsPtr->GetD(statsPtr);
}

unsigned int GetEntrySpA(PokemonEntry *obj) {
	PokemonStats *statsPtr = obj->mem->pokeStats;
	return statsPtr->GetSpA(statsPtr);
}

unsigned int GetEntrySpD(PokemonEntry *obj) {
	PokemonStats *statsPtr = obj->mem->pokeStats;
	return statsPtr->GetSpD(statsPtr);
}

unsigned int GetEntryS(PokemonEntry *obj) {
	PokemonStats *statsPtr = obj->mem->pokeStats;
	return statsPtr->GetS(statsPtr);
}

Type GetEntryPrimary(PokemonEntry* obj) {
	TypeContainer *typePtr = obj->mem->typeData;
	return typePtr->GetPrimary(typePtr);
}

Type GetEntrySecondary(PokemonEntry* obj) {
	TypeContainer *typePtr = obj->mem->typeData;
	return typePtr->GetSecondary(typePtr);
}

void PokemonEntryConsolePrint(PokemonEntry* obj) {
	printf("Name is %s\n", obj->mem->name);	
	PokemonStats *statsPtr = obj->mem->pokeStats;
	TypeContainer *typePtr = obj->mem->typeData;
	PokemonMoveSet *moveSetPtr = obj->mem->moveSet;	
	statsPtr->ConsolePrint(statsPtr);
	typePtr->ConsolePrint(typePtr);
	moveSetPtr->ConsolePrint(moveSetPtr);
	

//	PokemonStatsConsolePrint(obj->pokeStats);
//	TypeContainerConsolePrint(obj->typeData);
}









