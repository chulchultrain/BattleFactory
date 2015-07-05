
#include "Typing.h"
#include <stdlib.h>
#include <stdio.h>

TypeContainer *NewTypeContainer() {
	TypeContainer *result = malloc(sizeof(TypeContainer));
	SetTypeContainerFunctionPointers(result);


	return result;
}

TypeContainer *CopyTypeContainer(TypeContainer* original) {
	TypeContainer *result = malloc(sizeof(TypeContainer));
	result->primary = original->primary;
	result->secondary = original->secondary;
	SetTypeContainerFunctionPointers(result);
	return result;

}

TypeContainer *FullTypeContainer(Type* type1, Type* type2){
	TypeContainer *result = malloc(sizeof(TypeContainer));
	result->primary = *type1;
	result->secondary = *type2;
	SetTypeContainerFunctionPointers(result);	
	return result;

}

void ResetTypeContainerData(TypeContainer* recall) {
	recall->primary = NONE;
	recall->secondary = NONE;

}

void ResetTypeContainerPointers(TypeContainer* recall) {
	recall->SetPrimary = NULL;
	recall->SetSecondary = NULL;
	recall->SetBoth = NULL;
}

void ResetTypeContainerAll(TypeContainer* recall) {
	ResetTypeContainerData(recall);
	ResetTypeContainerPointers(recall);
}

void DeleteTypeContainer(TypeContainer* recall) {
	//reset so cant be recovered
	ResetTypeContainerAll(recall);
	free(recall);

}

void SetPrimaryType(TypeContainer* original,const Type* primary) {
	original->primary = *primary;
}

void SetSecondaryType(TypeContainer* original,const Type* secondary) {
	original->secondary = *secondary;
}

void SetBothTypes(TypeContainer* original,const Type* primary,const Type* secondary) {
	original->primary = *primary;
	original->secondary = *secondary;
}

void SetTypeContainerFunctionPointers(TypeContainer* original) {

	original->SetPrimary = SetPrimaryType;
	original->SetSecondary = SetSecondaryType;
	original->SetBoth = SetBothTypes;
}

void TypeConsolePrint(Type* obj) {
	printf("Type is ");
	switch(*obj) {
		case NONE: printf("NONE"); break;
		case NORMAL: printf("NORMAL"); break;
		case GRASS: printf("GRASS"); break;
		case BUG: printf("BUG"); break;
		case FIRE: printf("FIRE"); break;
		case WATER: printf("WATER"); break;
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
	TypeConsolePrint(&obj->primary);
	printf("Secondary ");
	TypeConsolePrint(&obj->secondary);
}


//maybe read typedata from premade textfile and construct a weaknesses/resistance table to not hardcode these things.
