
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

void SetPokemonMoveSetFirstMoveName(PokemonMoveSet *original, char *move);
void SetPokemonMoveSetSecondMoveName(PokemonMoveSet *original, char *move);
void SetPokemonMoveSetThirdMoveName(PokemonMoveSet *original, char *move);
void SetPokemonMoveSetFourthMoveName(PokemonMoveSet *original, char *move);

void GetPokemonMoveSetFirstMoveName(PokemonMoveSet *obj, char *dest, unsigned int limit);
void GetPokemonMoveSetSecondMoveName(PokemonMoveSet *obj, char *dest, unsigned int limit);
void GetPokemonMoveSetThirdMoveName(PokemonMoveSet *obj, char *dest, unsigned int limit);
void GetPokemonMoveSetFourthMoveName(PokemonMoveSet *obj, char *dest, unsigned int limit);

void SetPokemonMoveSetFirstMoveDamage(PokemonMoveSet *original, unsigned int damage);
void SetPokemonMoveSetSecondMoveDamage(PokemonMoveSet *original, unsigned int damage);
void SetPokemonMoveSetThirdMoveDamage(PokemonMoveSet *original, unsigned int damage);
void SetPokemonMoveSetFourthMoveDamage(PokemonMoveSet *original, unsigned int damage);

unsigned int GetPokemonMoveSetFirstMoveDamage(PokemonMoveSet *obj);
unsigned int GetPokemonMoveSetSecondMoveDamage(PokemonMoveSet *obj);
unsigned int GetPokemonMoveSetThirdMoveDamage(PokemonMoveSet *obj);
unsigned int GetPokemonMoveSetFourthMoveDamage(PokemonMoveSet *obj);

void SetPokemonMoveSetFirstMoveType(PokemonMoveSet *original, Type t);
void SetPokemonMoveSetSecondMoveType(PokemonMoveSet *original, Type t);
void SetPokemonMoveSetThirdMoveType(PokemonMoveSet *original, Type t);
void SetPokemonMoveSetFourthMoveType(PokemonMoveSet *original, Type t);

Type GetPokemonMoveSetFirstMoveType(PokemonMoveSet *obj);
Type GetPokemonMoveSetSecondMoveType(PokemonMoveSet *obj);
Type GetPokemonMoveSetThirdMoveType(PokemonMoveSet *obj);
Type GetPokemonMoveSetFourthMoveType(PokemonMoveSet *obj);


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
		original->SetFirstMoveName = SetPokemonMoveSetFirstMoveName;
		original->SetSecondMoveName = SetPokemonMoveSetSecondMoveName;
		original->SetThirdMoveName = SetPokemonMoveSetThirdMoveName;
		original->SetFourthMoveName = SetPokemonMoveSetFourthMoveName;
		original->GetFirstMoveName = GetPokemonMoveSetFirstMoveName;
		original->GetSecondMoveName = GetPokemonMoveSetSecondMoveName;
		original->GetThirdMoveName = GetPokemonMoveSetThirdMoveName;
		original->GetFourthMoveName = GetPokemonMoveSetFourthMoveName;
	
		original->ConsolePrint = PokemonMoveSetConsolePrint;

		original->SetFirstMoveDamage = SetPokemonMoveSetFirstMoveDamage;
		original->SetSecondMoveDamage = SetPokemonMoveSetSecondMoveDamage;
		original->SetThirdMoveDamage = SetPokemonMoveSetThirdMoveDamage;
		original->SetFourthMoveDamage = SetPokemonMoveSetFourthMoveDamage;

		original->SetFirstMoveType = SetPokemonMoveSetFirstMoveType;
		original->SetSecondMoveType = SetPokemonMoveSetSecondMoveType;
		original->SetThirdMoveType = SetPokemonMoveSetThirdMoveType;
		original->SetFourthMoveType = SetPokemonMoveSetFourthMoveType;

		original->GetFirstMoveDamage = GetPokemonMoveSetFirstMoveDamage;
		original->GetSecondMoveDamage = GetPokemonMoveSetSecondMoveDamage;
		original->GetThirdMoveDamage = GetPokemonMoveSetThirdMoveDamage;
		original->GetFourthMoveDamage = GetPokemonMoveSetFourthMoveDamage;

		original->GetFirstMoveType = GetPokemonMoveSetFirstMoveType;
		original->GetSecondMoveType = GetPokemonMoveSetSecondMoveType;
		original->GetThirdMoveType = GetPokemonMoveSetThirdMoveType;
		original->GetFourthMoveType = GetPokemonMoveSetFourthMoveType;




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

void SetPokemonMoveSetFirstMoveName(PokemonMoveSet *original, char *move) {
	original->mem->first->SetName(original->mem->first,move);	
}

void SetPokemonMoveSetSecondMoveName(PokemonMoveSet *original, char *move) {
	original->mem->second->SetName(original->mem->second,move);	
}

void SetPokemonMoveSetThirdMoveName(PokemonMoveSet *original, char *move) {
	original->mem->third->SetName(original->mem->third,move);	
}


void SetPokemonMoveSetFourthMoveName(PokemonMoveSet *original, char *move) {
	original->mem->fourth->SetName(original->mem->fourth,move);	
}

void GetPokemonMoveSetFirstMoveName(PokemonMoveSet *obj, char *dest, unsigned int limit) {
	obj->mem->first->GetName(obj->mem->first, dest, limit);
}

void GetPokemonMoveSetSecondMoveName(PokemonMoveSet *obj, char *dest, unsigned int limit) {
	obj->mem->second->GetName(obj->mem->second, dest, limit);
}

void GetPokemonMoveSetThirdMoveName(PokemonMoveSet *obj, char *dest, unsigned int limit) {
	obj->mem->third->GetName(obj->mem->third, dest, limit);
}

void GetPokemonMoveSetFourthMoveName(PokemonMoveSet *obj, char *dest, unsigned int limit) {
	obj->mem->fourth->GetName(obj->mem->fourth, dest, limit);
}


void SetPokemonMoveSetFirstMoveDamage(PokemonMoveSet *original, unsigned int damage) {
	original->mem->first->SetDamage(original->mem->first,damage);
}
void SetPokemonMoveSetSecondMoveDamage(PokemonMoveSet *original, unsigned int damage) {
	original->mem->second->SetDamage(original->mem->second,damage);
}
void SetPokemonMoveSetThirdMoveDamage(PokemonMoveSet *original, unsigned int damage) {
	original->mem->third->SetDamage(original->mem->third,damage);
}
void SetPokemonMoveSetFourthMoveDamage(PokemonMoveSet *original, unsigned int damage) {
	original->mem->fourth->SetDamage(original->mem->fourth,damage);
}

unsigned int GetPokemonMoveSetFirstMoveDamage(PokemonMoveSet *obj) {
	return obj->mem->first->GetDamage(obj->mem->first);
}

unsigned int GetPokemonMoveSetSecondMoveDamage(PokemonMoveSet *obj) {
	return obj->mem->second->GetDamage(obj->mem->second);
}


unsigned int GetPokemonMoveSetThirdMoveDamage(PokemonMoveSet *obj) {
	return obj->mem->third->GetDamage(obj->mem->third);
}

unsigned int GetPokemonMoveSetFourthMoveDamage(PokemonMoveSet *obj) {
	return obj->mem->fourth->GetDamage(obj->mem->fourth);
}

void SetPokemonMoveSetFirstMoveType(PokemonMoveSet *original, Type t) {
	original->mem->first->SetType(original->mem->first,t);
}


void SetPokemonMoveSetSecondMoveType(PokemonMoveSet *original, Type t) {
	original->mem->second->SetType(original->mem->second,t);
}

void SetPokemonMoveSetThirdMoveType(PokemonMoveSet *original, Type t) {
	original->mem->third->SetType(original->mem->third,t);
}

void SetPokemonMoveSetFourthMoveType(PokemonMoveSet *original, Type t) {
	original->mem->fourth->SetType(original->mem->fourth,t);
}

Type GetPokemonMoveSetFirstMoveType(PokemonMoveSet *obj) {
	return obj->mem->first->GetType(obj->mem->first);
}

Type GetPokemonMoveSetSecondMoveType(PokemonMoveSet *obj) {
	return obj->mem->second->GetType(obj->mem->second);
}

Type GetPokemonMoveSetThirdMoveType(PokemonMoveSet *obj) {
	return obj->mem->third->GetType(obj->mem->third);
}

Type GetPokemonMoveSetFourthMoveType(PokemonMoveSet *obj) {
	return obj->mem->fourth->GetType(obj->mem->fourth);
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




