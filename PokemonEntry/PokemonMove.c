#include <PokemonEntry/PokemonMove.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdlib.h>
#include <stdio.h>
#include <SpecialConstants/SpecialConstants.h>

struct PokemonMovePrivate {
	
unsigned int damage;
char name[MAX_MOVE_NAME];
Type moveType;
MoveCategory moveCat;

};

void SetPokemonMoveFunctionPointers(PokemonMove *movePtr);

void copyMoveName(const char* source, char* dest);
void SetPokemonMovePrivateData(PokemonMovePrivate *mem);


void MoveTypeConsolePrint(Type obj);
void MoveCategoryConsolePrint(MoveCategory obj);

void MoveConsolePrint(PokemonMove *obj);

void SetMoveName(PokemonMove *original, char *moveName);
void SetMoveDamage(PokemonMove *original, unsigned int D);
void SetMoveType(PokemonMove *original, Type t);
void SetMoveCategory(PokemonMove *original, MoveCategory m);

void GetMoveName(PokemonMove *obj, char *dest, unsigned int limit);
Type GetMoveType(PokemonMove *obj);
unsigned int GetMoveDamage(PokemonMove *obj);
MoveCategory GetMoveCategory(PokemonMove *obj);

//-------------------------------------



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

void SetPokemonMovePrivateData(PokemonMovePrivate *mem) {
	if(mem != 0) {
		mem->name[0] = 0;
		mem->damage = 0;
		mem->moveType = NONE;
		mem->moveCat = EMPTY;
	}
}

PokemonMove *NewPokemonMove() {
	PokemonMove *newPtr = malloc(sizeof(PokemonMove));
	if( newPtr == 0)
		GlobalDestroyer(1,0,0);
	newPtr->mem = malloc(sizeof(PokemonMovePrivate));
	if( newPtr->mem == 0)
		GlobalDestroyer(1,0,0);

	SetPokemonMovePrivateData(newPtr->mem);

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



void MoveTypeConsolePrint(Type obj) {
	printf("Type is ");
	switch(obj) {
		case NONE: printf("NONE"); break;
		case NORMAL: printf("NORMAL"); break;
		case GRASS: printf("GRASS"); break;
		case BUG: printf("BUG"); break;
		case FIRE: printf("FIRE"); break;
		case WATER: printf("WATER"); break;
		case ICE: printf("ICE"); break;
		case ELECTRIC: printf("ELECTRIC"); break;
		case FLYING: printf("FLYING"); break;
		case ROCK: printf("ROCK"); break;
		case GROUND: printf("GROUND"); break;
		case POISON: printf("POISON"); break;
		case PSYCHIC: printf("PSYCHIC"); break;
		case DARK: printf("DARK"); break;
		case STEEL: printf("STEEL"); break;
		case DRAGON: printf("DRAGON"); break;
		default: printf("INVALID TYPE");
	}
	printf("\n");

}

void MoveCategoryConsolePrint(MoveCategory obj) {
	printf("Move Category is ");
	switch(obj) {
			case NONE: printf("EMPTY"); break;
			case PHYSICAL: printf("PHYSICAL"); break;
			case SPECIAL: printf("SPECIAL"); break;
			case STATUS: printf("STATUS"); break;
			default: printf("INVALID MOVE CATEGORY");
		}
	printf(" ");
//	printf("\n");
}

void MoveConsolePrint(PokemonMove *obj) {
	printf("Move is %s. Damage is %u ", obj->mem->name, obj->mem->damage);
	MoveCategoryConsolePrint(obj->mem->moveCat);
	MoveTypeConsolePrint(obj->mem->moveType);

}

void SetMoveName(PokemonMove *original, char *moveName) {

	copyMoveName(moveName, original->mem->name);
}

void SetMoveDamage(PokemonMove *original, unsigned int D) {
	original->mem->damage = D;
}

unsigned int GetMoveDamage(PokemonMove *obj) {
	return obj->mem->damage;
}

void SetMoveType(PokemonMove *original, Type t) {
	original->mem->moveType = t;
}

Type GetMoveType(PokemonMove *obj) {
	return obj->mem->moveType;
}

void SetMoveCategory(PokemonMove *original, MoveCategory m) {
	original->mem->moveCat = m;
}

MoveCategory GetMoveCategory(PokemonMove *obj) {
	return obj->mem->moveCat;
}


void SetPokemonMoveFunctionPointers(PokemonMove *movePtr) {
	movePtr->SetName = SetMoveName;
	movePtr->GetName = GetMoveName;
	movePtr->ConsolePrint = MoveConsolePrint;
	//TODO:
	movePtr->SetDamage = SetMoveDamage;
	movePtr->GetDamage = GetMoveDamage;
	movePtr->SetType = SetMoveType;
	movePtr->GetType = GetMoveType;
	movePtr->SetCategory = SetMoveCategory;
	movePtr->GetCategory = GetMoveCategory;
}

void ResetPokemonMoveData(PokemonMove *recall) {
	if( recall != 0) {
		if( recall->mem != 0) {
			int i;
			for(i = 0; i < MAX_MOVE_NAME; i++)
				recall->mem->name[i] = 0;
				}
		recall->mem->damage = 0;
		recall->mem->moveType = NONE;
		recall->mem->moveCat = EMPTY;
	}

}

void DeletePokemonMove(PokemonMove *recall) {
	if( recall != 0) {
		if( recall->mem != 0) {
			free(recall->mem);
			recall->mem = 0;
		}
	free(recall);
	recall = 0;
	}

}


//-----------------------------
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

