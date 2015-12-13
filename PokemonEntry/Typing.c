
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
