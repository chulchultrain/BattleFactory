
#include <PokemonEntry/PokemonMoveSet.h>
#include <PokemonEntry/PokemonMove.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <SpecialConstants/SpecialConstants.h>
#include <stdlib.h>
#include <stdio.h>


struct PokemonMoveSetPrivate {

PokemonMove *moves[MAX_NUM_MOVES];

};

void SetPokemonMoveSetMoveName(PokemonMoveSet *original, unsigned int choice, char *move);

void GetPokemonMoveSetMoveName(PokemonMoveSet *obj, unsigned int choice, char *dest, unsigned int limit);

void SetPokemonMoveSetMoveDamage(PokemonMoveSet *original, unsigned int choice,unsigned int damage);

unsigned int GetPokemonMoveSetMoveDamage(PokemonMoveSet *obj, unsigned int choice);

void SetPokemonMoveSetMoveType(PokemonMoveSet *original, unsigned int choice,Type t);

Type GetPokemonMoveSetMoveType(PokemonMoveSet *obj, unsigned int choice);

void SetPokemonMoveSetMoveCategory(PokemonMoveSet *original, unsigned int choice, MoveCategory m);

MoveCategory GetPokemonMoveSetMoveCategory(PokemonMoveSet *obj, unsigned int choice);


void PokemonMoveSetConsolePrint(PokemonMoveSet *obj);

void MoveSetBoundaryAssertion(unsigned int choice);


void MoveSetAssertBounds(unsigned int choice) {
	if(choice >= MAX_NUM_MOVES || choice < 0)
		GlobalDestroyer(1,0,0);
}

void SetPokemonMoveSetMemory(PokemonMoveSetPrivate *memPtr) {
	if(memPtr != 0) {
		unsigned int i = 0;
		for(i = 0; i < MAX_NUM_MOVES; i++)
			memPtr->moves[i] = 0;

		for(i = 0; i < MAX_NUM_MOVES; i++)
			memPtr->moves[i] = NewPokemonMove();
	}

}

void SetPokemonMoveSetFunctionPointers(PokemonMoveSet *original) {
	if(original != 0) {
		original->SetMoveName = SetPokemonMoveSetMoveName;
		original->GetMoveName = GetPokemonMoveSetMoveName;
	
		original->ConsolePrint = PokemonMoveSetConsolePrint;
		original->SetMoveDamage = SetPokemonMoveSetMoveDamage;
		original->SetMoveType = SetPokemonMoveSetMoveType;
		original->GetMoveDamage = GetPokemonMoveSetMoveDamage;
		original->GetMoveType = GetPokemonMoveSetMoveType;

		original->SetMoveCategory = SetPokemonMoveSetMoveCategory;
		original->GetMoveCategory = GetPokemonMoveSetMoveCategory;


	}

}

PokemonMoveSet *NewPokemonMoveSet() {
	PokemonMoveSet *newPtr = malloc(sizeof(PokemonMoveSet));
	if(newPtr == 0) 
		GlobalDestroyer(1,0,0);
	newPtr->mem = malloc(sizeof(PokemonMoveSetPrivate));
	if(newPtr->mem == 0)
		GlobalDestroyer(1,0,0);
	SetPokemonMoveSetMemory(newPtr->mem);
	SetPokemonMoveSetFunctionPointers(newPtr);
	return newPtr;
	

}

void DeletePokemonMoveSet(PokemonMoveSet *recall) {
	if(recall != 0) {
		if(recall->mem != 0) {
			unsigned int i = 0;
			for(i = 0; i < MAX_NUM_MOVES; i++)
				if(recall->mem->moves[i] != 0) {
					DeletePokemonMove(recall->mem->moves[i]);
					recall->mem->moves[i] = 0; }
			
			free(recall->mem);
			recall->mem = 0;
		}
		free(recall);
		
	}
}

void SetPokemonMoveSetMoveName(PokemonMoveSet *original, unsigned int choice,char *move) {
	MoveSetAssertBounds(choice);
	PokemonMove *mPtr = original->mem->moves[choice];
	mPtr->SetName(mPtr,move);	
}

void GetPokemonMoveSetMoveName(PokemonMoveSet *obj, unsigned int choice, char *dest, unsigned int limit) {
	MoveSetAssertBounds(choice);
	PokemonMove *mPtr = obj->mem->moves[choice];
	mPtr->GetName(mPtr, dest, limit);
}


void SetPokemonMoveSetMoveDamage(PokemonMoveSet *original, unsigned int choice, unsigned int damage) {
	MoveSetAssertBounds(choice);
	PokemonMove *mPtr = original->mem->moves[choice];
	mPtr->SetDamage(mPtr,damage);
}

unsigned int GetPokemonMoveSetMoveDamage(PokemonMoveSet *obj, unsigned int choice) {
	MoveSetAssertBounds(choice);
	PokemonMove *mPtr = obj->mem->moves[choice];
	return mPtr->GetDamage(mPtr);
}

void SetPokemonMoveSetMoveType(PokemonMoveSet *original, unsigned int choice, Type t) {
	MoveSetAssertBounds(choice);
	PokemonMove *mPtr = original->mem->moves[choice];
	mPtr->SetType(mPtr,t);
}


Type GetPokemonMoveSetMoveType(PokemonMoveSet *obj, unsigned int choice) {
	MoveSetAssertBounds(choice);
	PokemonMove *mPtr = obj->mem->moves[choice];
	return mPtr->GetType(mPtr);
}

void SetPokemonMoveSetMoveCategory(PokemonMoveSet *original, unsigned int choice, MoveCategory m) {
	MoveSetAssertBounds(choice);
	PokemonMove *mPtr = original->mem->moves[choice];
	mPtr->SetCategory(mPtr,m);
}

MoveCategory GetPokemonMoveSetMoveCategory(PokemonMoveSet *obj, unsigned int choice) {
	MoveSetAssertBounds(choice);
	PokemonMove *mPtr = obj->mem->moves[choice];
	return mPtr->GetCategory(mPtr);
}


void PokemonMoveSetConsolePrint(PokemonMoveSet *obj) {
	if(obj != 0) {
		PokemonMoveSetPrivate *memPtr = obj->mem;
		unsigned int i = 0;
		printf("MoveSet:\n");
		for(i = 0; i < MAX_NUM_MOVES; i++)
			memPtr->moves[i]->ConsolePrint(memPtr->moves[i]);
	}
	else {
		printf("NULL MOVESET POINTER\n");
	}
}




