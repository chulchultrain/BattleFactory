
#include "Typing.h"
#include <stdlib.h>

TypeContainer *NewTypeContainer() {
	TypeContainer *result = malloc(sizeof(TypeContainer));
	return result;
}


//maybe read typedata from premade textfile and construct a weaknesses/resistance table to not hardcode these things.
