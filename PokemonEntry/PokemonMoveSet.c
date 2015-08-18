
#include <PokemonEntry/PokemonMoveSet.h>
#include <PokemonEntry/PokemonMove.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdlib.h>
#include <stdio.h>


struct PokemonMoveSetPrivate {

PokemonMove *first;
PokemonMove *second;
PokemonMove *third;
PokemonMove *fourth;

};

void SetPokemonMoveSetFirstMove(PokemonMoveSet *original, char *move);
void SetPokemonMoveSetSecondMove(PokemonMoveSet *original, char *move);
void SetPokemonMoveSetThirdMove(PokemonMoveSet *original, char *move);
void SetPokemonMoveSetFourthMove(PokemonMoveSet *original, char *move);

void GetPokemonMoveSetFirstMove(PokemonMoveSet *obj, char *dest, unsigned int limit);
void GetPokemonMoveSetSecondMove(PokemonMoveSet *obj, char *dest, unsigned int limit);
void GetPokemonMoveSetThirdMove(PokemonMoveSet *obj, char *dest, unsigned int limit);
void GetPokemonMoveSetFourthMove(PokemonMoveSet *obj, char *dest, unsigned int limit);

void PokemonMoveSetConsolePrint(PokemonMoveSet *obj);


void SetPokemonMoveSetMemory(PokemonMoveSetPrivate *memPtr) {
	if(memPtr != 0) {
		memPtr->first = 0;
		memPtr->second = 0;
		memPtr->third = 0;
		memPtr->fourth = 0;
		memPtr->first = NewPokemonMove();
		memPtr->second = NewPokemonMove();
		memPtr->third = NewPokemonMove();
		memPtr->fourth = NewPokemonMove();
	}

}

void SetPokemonMoveSetFunctionPointers(PokemonMoveSet *original) {
	if(original != 0) {
		original->SetFirstMove = SetPokemonMoveSetFirstMove;
		original->SetSecondMove = SetPokemonMoveSetSecondMove;
		original->SetThirdMove = SetPokemonMoveSetThirdMove;
		original->SetFourthMove = SetPokemonMoveSetFourthMove;
		original->GetFirstMove = GetPokemonMoveSetFirstMove;
		original->GetSecondMove = GetPokemonMoveSetSecondMove;
		original->GetThirdMove = GetPokemonMoveSetThirdMove;
		original->GetFourthMove = GetPokemonMoveSetFourthMove;
		original->ConsolePrint = PokemonMoveSetConsolePrint;

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
			if(recall->mem->first != 0) {
				DeletePokemonMove(recall->mem->first);
				recall->mem->first = 0; }
			if(recall->mem->second != 0) {
				DeletePokemonMove(recall->mem->second);
				recall->mem->second = 0; }
			if(recall->mem->third != 0) {
				DeletePokemonMove(recall->mem->third);
				recall->mem->third = 0; }
			if(recall->mem->fourth != 0) {
				DeletePokemonMove(recall->mem->fourth);
				recall->mem->fourth = 0; }
			free(recall->mem);
			recall->mem = 0;
		}
		free(recall);
		
	}

}

void SetPokemonMoveSetFirstMove(PokemonMoveSet *original, char *move) {
	original->mem->first->SetName(original->mem->first,move);	
}

void SetPokemonMoveSetSecondMove(PokemonMoveSet *original, char *move) {
	original->mem->second->SetName(original->mem->second,move);	
}

void SetPokemonMoveSetThirdMove(PokemonMoveSet *original, char *move) {
	original->mem->third->SetName(original->mem->third,move);	
}


void SetPokemonMoveSetFourthMove(PokemonMoveSet *original, char *move) {
	original->mem->fourth->SetName(original->mem->fourth,move);	
}

void GetPokemonMoveSetFirstMove(PokemonMoveSet *obj, char *dest, unsigned int limit) {
	obj->mem->first->GetName(obj->mem->first, dest, limit);
}

void GetPokemonMoveSetSecondMove(PokemonMoveSet *obj, char *dest, unsigned int limit) {
	obj->mem->second->GetName(obj->mem->second, dest, limit);
}

void GetPokemonMoveSetThirdMove(PokemonMoveSet *obj, char *dest, unsigned int limit) {
	obj->mem->third->GetName(obj->mem->third, dest, limit);
}

void GetPokemonMoveSetFourthMove(PokemonMoveSet *obj, char *dest, unsigned int limit) {
	obj->mem->fourth->GetName(obj->mem->fourth, dest, limit);
}

void PokemonMoveSetConsolePrint(PokemonMoveSet *obj) {
	if(obj != 0) {
		PokemonMoveSetPrivate *memPtr = obj->mem;
		printf("First ");
		memPtr->first->ConsolePrint(memPtr->first);
		printf("Second ");
		memPtr->second->ConsolePrint(memPtr->second);
		printf("Third ");
		memPtr->third->ConsolePrint(memPtr->third);
		printf("Fourth ");
		memPtr->fourth->ConsolePrint(memPtr->fourth);
	}
	else {
		printf("NULL MOVESET POINTER\n");
	}
}




