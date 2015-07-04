
#include "Typing.h"
#include <stdlib.h>

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

void DeleteTypeContainer(TypeContainer* recall) {
	//reset so cant be recovered
	recall->primary = NONE;
	recall->secondary = NONE;
	recall->SetPrimary = NULL;
	recall->SetSecondary = NULL;
	recall->SetBoth = NULL;
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


//maybe read typedata from premade textfile and construct a weaknesses/resistance table to not hardcode these things.
