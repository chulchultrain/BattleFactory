#include <PokemonEntry/PokemonMove.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdlib.h>
#include <stdio.h>


#ifndef MAX_MOVE_NAME
#define MAX_MOVE_NAME 21
#endif

struct PokemonMovePrivate {
	
char name[MAX_MOVE_NAME];

};

void SetPokemonMoveFunctionPointers(PokemonMove *movePtr);

void copyMoveName(const char* source, char* dest) {
	int i = 0;
	while(i < MAX_MOVE_NAME && source[i] != 0) {
		dest[i] = source[i];
		i++;
	}

	if(i == MAX_MOVE_NAME) //took up all the space so must truncate for'\0'
		dest[MAX_MOVE_NAME - 1] = 0;
	else
		dest[i] = 0; //append '\0'
}


PokemonMove *NewPokemonMove() {
	PokemonMove *newPtr = malloc(sizeof(PokemonMove));
	if( newPtr == 0)
		GlobalDestroyer(1,0,0);
	newPtr->mem = malloc(sizeof(PokemonMovePrivate));
	if( newPtr->mem == 0)
		GlobalDestroyer(1,0,0);
	newPtr->mem->name[0] = 0;

	SetPokemonMoveFunctionPointers(newPtr);
	return newPtr;
}

void GetMoveName(PokemonMove *obj, char *dest, unsigned int limit) {
	unsigned int i;
	unsigned int m = -1;
	if(limit > MAX_MOVE_NAME)
		m = limit;
	else
		m = MAX_MOVE_NAME;
	for(i = 0; i<m; i++) {
		dest[i] = obj->mem->name[i];
	}	
}

void MoveConsolePrint(PokemonMove *obj) {
	printf("Move is %s\n", obj->mem->name);
}

void SetMoveName(PokemonMove *original, char *moveName) {

	copyMoveName(moveName, original->mem->name);
}


void SetPokemonMoveFunctionPointers(PokemonMove *movePtr) {
	movePtr->SetName = SetMoveName;
	movePtr->GetName = GetMoveName;
	movePtr->ConsolePrint = MoveConsolePrint;
}

void ResetPokemonMoveData(PokemonMove *recall) {
	if( recall != 0) {
		if( recall->mem != 0) {
			int i;
			for(i = 0; i < MAX_MOVE_NAME; i++)
				recall->mem->name[i] = 0;
				}

	}

}

void DestroyPokemonMove(PokemonMove *recall) {
	if( recall != 0) {
		if( recall->mem != 0) {
			free(recall->mem);
			recall->mem = 0;
		}
	free(recall);
	recall = 0;
	}

}
