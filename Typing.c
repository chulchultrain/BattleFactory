
#include "Typing.h"
#include <stdlib.h>

TypeContainer *NewTypeContainer() {
	TypeContainer *result = malloc(sizeof(TypeContainer));
	return result;
}

TypeContainer *CopyTypeContainer(TypeContainer* original) {
	TypeContainer *result = malloc(sizeof(TypeContainer));
	result->primary = original->primary;
	result->secondary = original->secondary;
	return result;

}

TypeContainer *FullTypeContainer(Type* type1, Type* type2){
	TypeContainer *result = malloc(sizeof(TypeContainer));
	result->primary = *type1;
	result->secondary = *type2;
	
	return result;

}

void DeleteTypeContainer(TypeContainer* recall) {
	free(recall);

}


void SetPrimaryType(TypeContainer* original, Type* primary) {
	original->primary = *primary;
}

void SetSecondaryType(TypeContainer* original, Type* secondary) {
	original->secondary = *secondary;
}

void SetBothTypes(TypeContainer* original, Type* primary, Type* secondary) {
	original->primary = *primary;
	original->secondary = *secondary;
}


//maybe read typedata from premade textfile and construct a weaknesses/resistance table to not hardcode these things.
