
#include <PokemonEntry/PokemonEntry.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdlib.h>
#include <stdio.h>
#include <PokemonEntry/Typing.h>
#include <PokemonEntry/PokemonStats.h>
#include <PokemonEntry/PokemonMoveSet.h>
#include <SpecialConstants/SpecialConstants.h>

struct PokemonEntryPrivate {

TypeContainer *typeData;

char name[MAX_NAME];
//weaknesses/resistances/normal list
//moveset

PokemonStats *pokeStats;
PokemonMoveSet *moveSet;

};

void SetPokemonName(PokemonEntry* original, const char* name);


void SetEntryHP(PokemonEntry* original, const int* HP);



void SetEntryHP(PokemonEntry* original, const int* HP);
void SetEntryA(PokemonEntry* original, const int* A);
void SetEntryD(PokemonEntry* original, const int* D);
void SetEntrySpA(PokemonEntry* original, const int* SpA);
void SetEntrySpD(PokemonEntry* original, const int* SpD);
void SetEntryS(PokemonEntry* original, const int* S);

void SetEntryPrimaryType(PokemonEntry* original, const Type* primary);
void SetEntrySecondaryType(PokemonEntry* original, const Type* secondary);

void SetEntryFirstMove(PokemonEntry *original, char *move, unsigned int *d, Type *t, MoveCategory *m);
void SetEntrySecondMove(PokemonEntry *original, char *move, unsigned int *d, Type *t, MoveCategory *m);
void SetEntryThirdMove(PokemonEntry *original, char *move, unsigned int *d, Type *t, MoveCategory *m);
void SetEntryFourthMove(PokemonEntry *original, char *move, unsigned int *d, Type *t, MoveCategory *m);

void GetEntryFirstMoveName(PokemonEntry *original, char *dest, unsigned int limit);
void GetEntrySecondMoveName(PokemonEntry *original, char *dest, unsigned int limit);
void GetEntryThirdMoveName(PokemonEntry *original, char *dest, unsigned int limit);
void GetEntryFourthMoveName(PokemonEntry *original, char *dest, unsigned int limit);

unsigned int GetEntryFirstMoveDamage(PokemonEntry *obj);
unsigned int GetEntrySecondMoveDamage(PokemonEntry *obj);
unsigned int GetEntryThirdMoveDamage(PokemonEntry *obj);
unsigned int GetEntryFourthMoveDamage(PokemonEntry *obj);

Type GetEntryFirstMoveType(PokemonEntry *obj);
Type GetEntrySecondMoveType(PokemonEntry *obj);
Type GetEntryThirdMoveType(PokemonEntry *obj);
Type GetEntryFourthMoveType(PokemonEntry *obj);

MoveCategory GetEntryFirstMoveCategory(PokemonEntry *obj);
MoveCategory GetEntrySecondMoveCategory(PokemonEntry *obj);
MoveCategory GetEntryThirdMoveCategory(PokemonEntry *obj);
MoveCategory GetEntryFourthMoveCategory(PokemonEntry *obj);

void GetEntryName(PokemonEntry *obj, char* dest, unsigned int limit);

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
void copyName(const char* source, char* dest) {
	int i = 0;
	while(i < MAX_NAME && source[i] != 0) {
		dest[i] = source[i];
		i++;
	}
	if(i == MAX_NAME) //took up all the space so must truncate for'\0'
		dest[MAX_NAME - 1] = 0;
	else
		dest[i] = 0; //append '\0'
}
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

	GlobalDestroyer(0,result,0);	

	result->mem = malloc(sizeof(PokemonEntryPrivate));
	if( result->mem == 0) {
		GlobalDestroyer(1,0,0);
	}
	SetPokemonEntryMemory(result->mem);
	SetPokemonEntryFunctionPointers(result);
	return result;

}

//TODO:POKEMONENTRY COPY CONSTRUCTOR
/** but before I can do this I need getter functions
PokemonEntry *CopyPokemonEntry(PokemonEntry* obj) {
	PokemonEntry *result = NewPokemonEntry(obj);
}
**/
/*If we're gonna make a full pokemon stats, might as well make full new pokemon
  entry. Will include stats, type and name
*/

/**
Deprecated:
PokemonEntry *FullPokemonEntry(char* name, PokemonStats* statsHolder, TypeContainer* typeHolder) {
	int i;
	for(i = 0; i < MAX_NAME; i++)
		if(name[i] == 0)
			break;
	if(i == MAX_NAME)
		return NULL; //TODO:assert. name > 20c should have already checked
	PokemonEntry *result = malloc(sizeof(PokemonEntry));
	result->mem = malloc(sizeof(PokemonEntryPrivate));
	copyName(name, result->mem->name);
	result->mem->typeData = CopyTypeContainer(typeHolder); //TODO:CopyConstructor
	result->mem->pokeStats = CopyPokemonStats(statsHolder); //TODO:CopyConstructor
	SetPokemonEntryFunctionPointers(result);
	return result;


}
**/

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


/**
void ResetPokemonEntryPointers(PokemonEntry* recall) {
	recall->SetName = NULL;
	recall->SetHitPoints = NULL;
	recall->SetAttack = NULL;
	recall->SetDefense = NULL;
	recall->SetSpecialAttack = NULL;
	recall->SetSpecialDefense = NULL;
	recall->SetSpeed = NULL;
	recall->SetPrimaryType = NULL;
	recall->SetSecondaryType = NULL;
	recall->Get
	ResetPokemonStatsPointers(recall->mem->pokeStats);
	ResetTypeContainerPointers(recall->mem->typeData);
}
**/
void ResetPokemonEntryAll(PokemonEntry* recall) {
	ResetPokemonEntryData(recall);
//	ResetPokemonEntryPointers(recall);
}

void DeletePokemonEntry(PokemonEntry* recall){
	//zero out name before free
	if(recall != 0) {
		if(recall->mem != 0) {
			ResetPokemonEntryData(recall);
			if(recall->mem->pokeStats != 0) {
				DeletePokemonStats(recall->mem->pokeStats);
				recall->mem->pokeStats = 0;
				printf("pokemonStats address is %p\n", recall->mem->pokeStats); }
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
	
}

void SetPokemonName(PokemonEntry* original, const char* name) {	
	copyName(name, original->mem->name);
}



void SetPokemonEntryFunctionPointers(PokemonEntry* original) {
	original->SetName = SetPokemonName;
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
	original->GetHitPoints = GetEntryHP;
	original->GetAttack = GetEntryA;
	original->GetDefense = GetEntryD;
	original->GetSpecialAttack = GetEntrySpA;
	original->GetSpecialDefense = GetEntrySpD;
	original->GetSpeed = GetEntryS;

	original->SetFirstMove = SetEntryFirstMove;
	original->SetSecondMove = SetEntrySecondMove;
	original->SetThirdMove = SetEntryThirdMove;
	original->SetFourthMove = SetEntryFourthMove;
	original->GetFirstMoveName = GetEntryFirstMoveName;
	original->GetSecondMoveName = GetEntrySecondMoveName;
	original->GetThirdMoveName = GetEntryThirdMoveName;
	original->GetFourthMoveName = GetEntryFourthMoveName;

	original->GetFirstMoveDamage = GetEntryFirstMoveDamage;
	original->GetSecondMoveDamage = GetEntrySecondMoveDamage;
	original->GetThirdMoveDamage = GetEntryThirdMoveDamage;
	original->GetFourthMoveDamage = GetEntryFourthMoveDamage;

	original->GetFirstMoveType = GetEntryFirstMoveType;
	original->GetSecondMoveType = GetEntrySecondMoveType;
	original->GetThirdMoveType = GetEntryThirdMoveType;
	original->GetFourthMoveType = GetEntryFourthMoveType;

	original->GetFirstMoveCategory = GetEntryFirstMoveCategory;
	original->GetSecondMoveCategory = GetEntrySecondMoveCategory;
	original->GetThirdMoveCategory = GetEntryThirdMoveCategory;
	original->GetFourthMoveCategory = GetEntryFourthMoveCategory;

}

void SetEntryHP(PokemonEntry* original, const int* HP) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetHP(statsPtr, HP);
	
//	SetHitPoints(original->pokeStats, HP);
}

void SetEntryA(PokemonEntry* original, const int* A) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetA(statsPtr, A);
//	SetAttack(original->pokeStats, A);
}

void SetEntryD(PokemonEntry* original, const int* D) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetD(statsPtr, D);
//	SetDefense(original->pokeStats, D);
}

void SetEntrySpA(PokemonEntry* original, const int* SpA) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetSpA(statsPtr, SpA);
//	SetSpecialAttack(original->pokeStats, SpA);
}

void SetEntrySpD(PokemonEntry* original, const int* SpD) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetSpD(statsPtr, SpD);
//	SetSpecialDefense(original->pokeStats, SpD);
}

void SetEntryS(PokemonEntry* original, const int* S) {
	PokemonStats *statsPtr = original->mem->pokeStats;
	statsPtr->SetS(statsPtr, S);
//	SetSpeed(original->pokeStats, S);
}

void SetEntryPrimaryType(PokemonEntry* original, const Type* primary) {
	TypeContainer *typePtr = original->mem->typeData;
	typePtr->SetPrimary(typePtr, primary);
//	SetPrimaryType(original->typeData, primary);
}

void SetEntrySecondaryType(PokemonEntry* original, const Type* secondary) {
	TypeContainer *typePtr = original->mem->typeData;
	typePtr->SetSecondary(typePtr, secondary);
//	SetSecondaryType(original->typeData, secondary);
}

void SetEntryFirstMove(PokemonEntry *original, char *move, unsigned int *d, Type *t, MoveCategory *m) {
	original->mem->moveSet->SetFirstMoveName(original->mem->moveSet, move);
	original->mem->moveSet->SetFirstMoveDamage(original->mem->moveSet,d);
	original->mem->moveSet->SetFirstMoveType(original->mem->moveSet,t);
	original->mem->moveSet->SetFirstMoveCategory(original->mem->moveSet,m);
}

void SetEntrySecondMove(PokemonEntry *original, char *move, unsigned int *d, Type *t, MoveCategory *m) {
	original->mem->moveSet->SetSecondMoveName(original->mem->moveSet, move);
	original->mem->moveSet->SetSecondMoveDamage(original->mem->moveSet,d);
	original->mem->moveSet->SetSecondMoveType(original->mem->moveSet,t);
	original->mem->moveSet->SetSecondMoveCategory(original->mem->moveSet,m);
}

void SetEntryThirdMove(PokemonEntry *original, char *move, unsigned int *d, Type *t, MoveCategory *m) {
	original->mem->moveSet->SetThirdMoveName(original->mem->moveSet, move);
	original->mem->moveSet->SetThirdMoveDamage(original->mem->moveSet,d);
	original->mem->moveSet->SetThirdMoveType(original->mem->moveSet,t);
	original->mem->moveSet->SetThirdMoveCategory(original->mem->moveSet,m);
}

void SetEntryFourthMove(PokemonEntry *original, char *move, unsigned int *d, Type *t, MoveCategory *m) {
	original->mem->moveSet->SetFourthMoveName(original->mem->moveSet, move);
	original->mem->moveSet->SetFourthMoveDamage(original->mem->moveSet,d);
	original->mem->moveSet->SetFourthMoveType(original->mem->moveSet,t);
	original->mem->moveSet->SetFourthMoveCategory(original->mem->moveSet,m);
}

void GetEntryFirstMoveName(PokemonEntry *original, char *move, unsigned int limit) {
	original->mem->moveSet->GetFirstMoveName(original->mem->moveSet, move, limit);
}

void GetEntrySecondMoveName(PokemonEntry *original, char *move, unsigned int limit) {
	original->mem->moveSet->GetSecondMoveName(original->mem->moveSet, move, limit);
}

void GetEntryThirdMoveName(PokemonEntry *original, char *move, unsigned int limit) {
	original->mem->moveSet->GetThirdMoveName(original->mem->moveSet, move, limit);
}

void GetEntryFourthMoveName(PokemonEntry *original, char *move, unsigned int limit) {
	original->mem->moveSet->GetFourthMoveName(original->mem->moveSet, move, limit);
}

unsigned int GetEntryFirstMoveDamage(PokemonEntry *obj) {
	return obj->mem->moveSet->GetFirstMoveDamage(obj->mem->moveSet);	
}

unsigned int GetEntrySecondMoveDamage(PokemonEntry *obj) {
	return obj->mem->moveSet->GetSecondMoveDamage(obj->mem->moveSet);	
}

unsigned int GetEntryThirdMoveDamage(PokemonEntry *obj) {
	return obj->mem->moveSet->GetThirdMoveDamage(obj->mem->moveSet);	
}

unsigned int GetEntryFourthMoveDamage(PokemonEntry *obj) {
	return obj->mem->moveSet->GetFourthMoveDamage(obj->mem->moveSet);	
}

Type GetEntryFirstMoveType(PokemonEntry *obj) {
	return obj->mem->moveSet->GetFirstMoveType(obj->mem->moveSet);	
}

Type GetEntrySecondMoveType(PokemonEntry *obj) {
	return obj->mem->moveSet->GetSecondMoveType(obj->mem->moveSet);	

}

Type GetEntryThirdMoveType(PokemonEntry *obj) {
	return obj->mem->moveSet->GetThirdMoveType(obj->mem->moveSet);	
}

Type GetEntryFourthMoveType(PokemonEntry *obj) {
	return obj->mem->moveSet->GetFourthMoveType(obj->mem->moveSet);	
}

MoveCategory GetEntryFirstMoveCategory(PokemonEntry *obj) {
	return obj->mem->moveSet->GetFirstMoveCategory(obj->mem->moveSet);
}
MoveCategory GetEntrySecondMoveCategory(PokemonEntry *obj) {
	return obj->mem->moveSet->GetSecondMoveCategory(obj->mem->moveSet);
}
MoveCategory GetEntryThirdMoveCategory(PokemonEntry *obj) {
	return obj->mem->moveSet->GetThirdMoveCategory(obj->mem->moveSet);
}
MoveCategory GetEntryFourthMoveCategory(PokemonEntry *obj) {
	return obj->mem->moveSet->GetFourthMoveCategory(obj->mem->moveSet);
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









