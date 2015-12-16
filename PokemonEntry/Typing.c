
#include <PokemonEntry/Typing.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <stdlib.h>
#include <stdio.h>



struct TypeContainerPrivate {

	Type primary;
	Type secondary;
};



void SetPrimaryType(TypeContainer* original, Type primary);

void SetSecondaryType(TypeContainer* original, Type secondary);

void SetBothTypes(TypeContainer* original, Type primary, Type secondary);

void SetTypeContainerFunctionPointers(TypeContainer* original);

void TypeConsolePrint(Type obj);

void TypeContainerConsolePrint(TypeContainer* obj);

Type GetPrimaryType(TypeContainer* obj);

Type GetSecondaryType(TypeContainer* obj);

void SetTypeContainerMemory(TypeContainerPrivate *memPtr) {
	if (memPtr != 0) {
		memPtr->primary = NONE;
		memPtr->secondary = NONE;
	}
}

TypeContainer *NewTypeContainer() {
	TypeContainer *result = malloc(sizeof(TypeContainer));
	if (result == 0)
		GlobalDestroyer(1,0,0);
	result->mem = malloc(sizeof(TypeContainerPrivate));
	if (result->mem == 0) {
		GlobalDestroyer(1,0,0); 
		}

	SetTypeContainerMemory(result->mem);
	SetTypeContainerFunctionPointers(result);
	ResetTypeContainerData(result);

	return result;
}

//TODO:TEST
TypeContainer *CopyTypeContainer(TypeContainer* original) {
	TypeContainer *result = malloc(sizeof(TypeContainer));
	if (result == 0)
		GlobalDestroyer(1,0,0);
	result->mem = malloc(sizeof(TypeContainerPrivate));
	if (result->mem == 0)
		GlobalDestroyer(1,0,0);
	SetTypeContainerMemory(result->mem);
	result->mem->primary = original->mem->primary;
	result->mem->secondary = original->mem->secondary;
	SetTypeContainerFunctionPointers(result);
	return result;

}

TypeContainer *FullTypeContainer(Type type1, Type type2){
	TypeContainer *result = malloc(sizeof(TypeContainer));
	if (result == 0)
		GlobalDestroyer(1,0,0);
	result->mem = malloc(sizeof(TypeContainerPrivate));
	if (result->mem == 0)
		GlobalDestroyer(1,0,0);
	SetTypeContainerMemory(result->mem);
	result->mem->primary = type1;
	result->mem->secondary = type2;
	SetTypeContainerFunctionPointers(result);	
	return result;

}

void ResetTypeContainerData(TypeContainer* recall) {
	if(recall != 0) {
		if(recall->mem != 0) { 
			recall->mem->primary = NONE;
			recall->mem->secondary = NONE;} 
		}
}
/**
void ResetTypeContainerPointers(TypeContainer* recall) {
	recall->SetPrimary = NULL;
	recall->SetSecondary = NULL;
	recall->SetBoth = NULL;
}
**/
void ResetTypeContainerAll(TypeContainer* recall) {
	ResetTypeContainerData(recall);
//	ResetTypeContainerPointers(recall);
}

void DeleteTypeContainer(TypeContainer* recall) {
	//reset so cant be recovered
	if(recall != 0) {
		if(recall->mem != 0) {
			ResetTypeContainerData(recall);
			free(recall->mem);
			recall->mem = 0;
					}
		free(recall); 
		 }

}

void SetPrimaryType(TypeContainer* original, Type primary) {
	original->mem->primary = primary;
}

void SetSecondaryType(TypeContainer* original, Type secondary) {
	original->mem->secondary = secondary;
}

void SetBothTypes(TypeContainer* original,Type primary, Type secondary) {
	original->mem->primary = primary;
	original->mem->secondary = secondary;
}

void SetTypeContainerFunctionPointers(TypeContainer* original) {

	original->SetPrimary = SetPrimaryType;
	original->SetSecondary = SetSecondaryType;
	original->SetBoth = SetBothTypes;
	original->ConsolePrint = TypeContainerConsolePrint;
	original->GetPrimary = GetPrimaryType;
	original->GetSecondary = GetSecondaryType;
}

void TypeConsolePrint(Type obj) {
	printf("Type is ");
	switch(obj) {
		case NONE: printf("NONE"); break;
		case NORMAL: printf("NORMAL"); break;
		case FIGHTING: printf("FIGHTING"); break;
		case FAIRY: printf("FAIRY"); break;
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

void TypeContainerConsolePrint(TypeContainer* obj) {
	printf("Primary ");
	TypeConsolePrint(obj->mem->primary);
	printf("Secondary ");
	TypeConsolePrint(obj->mem->secondary);
}

Type GetPrimaryType(TypeContainer* obj) {
	return obj->mem->primary;
}

Type GetSecondaryType(TypeContainer* obj) {
	return obj->mem->secondary;
}


//maybe read typedata from premade textfile and construct a weaknesses/resistance table to not hardcode these things.


/*
To make more efficient later, and to keep from re creating a huge array every tiem we call upon DamageModFromTypes, we should
keep a global data struct for this. Or perhaps to just have 1 and pass it into the parameters of this.
*/
double DamageModFromTypes(Type attack, Type defend) {
	double mod[MAX_TYPES][MAX_TYPES];

	int i,j;
	for(i = 0; i < MAX_TYPES; i++)
		for(j = 0; j < MAX_TYPES; j++)
			mod[i][j] = 1;

	mod[NORMAL][ROCK] = mod[NORMAL][STEEL] = .5;
	mod[NORMAL][GHOST] = 0;

	mod[FIGHTING][NORMAL] = mod[FIGHTING][ROCK] = mod[FIGHTING][STEEL] = mod[FIGHTING][DARK] = mod[FIGHTING][ICE] = 2;
	mod[FIGHTING][FLYING] = mod[FIGHTING][POISON] = mod[FIGHTING][BUG] = mod[FIGHTING][PSYCHIC] = .5;
	mod[FIGHTING][GHOST] = 0;
	
	mod[FLYING][FIGHTING] = mod[FLYING][BUG] = mod[FLYING][GRASS] = 2;
	mod[FLYING][ROCK] = mod[FLYING][STEEL] = mod[FLYING][ELECTRIC] = .5;
	
	mod[POISON][GRASS] = 2;
	mod[POISON][POISON] = mod[POISON][GROUND] = mod[POISON][ROCK] = mod[POISON][GHOST] = .5;
	mod[POISON][STEEL] = 0;

	mod[GROUND][POISON] = mod[GROUND][ROCK] = mod[GROUND][STEEL] = mod[GROUND][FIRE] = mod[GROUND][ELECTRIC] = 2;
	mod[GROUND][BUG] = mod[GROUND][GRASS] = .5;
	mod[GROUND][FLYING] = 0;

	mod[ROCK][FLYING] = mod[ROCK][BUG] = mod[ROCK][FIRE] = mod[ROCK][ICE] = 2;
	mod[ROCK][FIGHTING] = mod[ROCK][GROUND] = mod[ROCK][STEEL] = .5;
	
	mod[BUG][GRASS] = mod[BUG][PSYCHIC] = mod[BUG][DARK] = 2;
	mod[BUG][FIGHTING] = mod[BUG][FLYING] = mod[BUG][POISON] = mod[BUG][GHOST] = mod[BUG][STEEL] = mod[BUG][FIRE] = .5;


	mod[GHOST][GHOST] = mod[GHOST][PSYCHIC] = 2;
	mod[GHOST][DARK] = mod[GHOST][STEEL] = .5;
	mod[GHOST][NORMAL] = 0;
	
	mod[STEEL][ROCK] = mod[STEEL][ICE] = 2;
	mod[STEEL][FIRE] = mod[STEEL][WATER] mod[STEEL][STEEL] = mod[STEEL][ELECTRIC] = .5;
	
	mod[FIRE][BUG] = mod[FIRE][STEEL] = mod[FIRE][GRASS] = mod[FIRE][ICE] = 2;
	mod[FIRE][ROCK] = mod[FIRE][FIRE] = mod[FIRE][WATER] = mod[FIRE][DRAGON] = .5;

	mod[WATER][GROUND] = mod[WATER][ROCK] = mod[WATER][FIRE] = 2;
	mod[WATER][WATER] = mod[WATER][GRASS] = mod[WATER][DRAGON] = .5;
	
	mod[GRASS][GROUND] = mod[GRASS][ROCK] = mod[GRASS][WATER] = 2;
	mod[GRASS][FLYING] = mod[GRASS][POISON] = mod[GRASS][BUG] = mod[GRASS][STEEL] = .5;
	mod[GRASS][FIRE] = mod[GRASS][GRASS] = mod[GRASS][DRAGON] = .5;

	mod[ELECTRIC][FLYING] = mod[ELECTRIC][WATER] = 2;
	mod[ELECTRIC][GRASS] = mod[ELECTRIC][ELECTRIC] = mod[ELECTRIC][DRAGON] = .5;
	mod[ELECTRIC][GROUND] = .5;
	
	mod[PSYCHIC][FIGHTING] = mod[PSYCHIC][POISON] = 2;
	mod[PSYCHIC][STEEL] = mod[PSYCHIC][PSYCHIC] = .5;
	mod[PSYCHIC][DARK] = 0;

	mod[ICE][FLYING] = mod[ICE][GROUND] = mod[ICE][GRASS] = mod[ICE][DRAGON] = 2;
	mod[ICE][STEEL] = mod[ICE][FIRE] = mod[ICE][WATER] = mod[ICE][ICE] = .5;

	mod[DRAGON][DRAGON] = 2;
	mod[DRAGON][STEEL] = .5;

	mod[DARK][PSYCHIC] = mod[DARK][GHOST] = 2;
	mod[DARK][FIGHTING] = mod[DARK][STEEL] = mod[DARK][DARK] = .5;
	
	return mod[attack][defend];

}





