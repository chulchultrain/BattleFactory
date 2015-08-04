#include <Pokedex/Pokedex.h>
#include <GlobalDestroyer/GlobalDestroyer.h>

#include <stdlib.h>
#include <stdio.h>

#ifndef MAX_POKEDEX_LINE
#define MAX_POKEDEX_LINE 70
#endif

struct PokedexPrivate {
	PokedexEntry *table[MAX_POKEMON_NUMBER];

};

//TODO:CHANGE FUNCTION BACK TO 1 param when I get static destroyer function
PokedexEntry *CopyPokedexEntry(Pokedex *table, PokedexEntry *obj);

unsigned int HashFunction(char *name);


void ConsolePrintPokedexEntry(PokedexEntry *obj);



//CP'd from PokemonEntry.c
void copyPokedexName(const char* source, char* dest) {
	int i = 0;
	while(i < MAX_NAME && source[i] != 0) {
		dest[i] = source[i];
		i++;
	}
	if(i == MAX_NAME) //took up all the space so must truncate for'\0'
		dest[MAX_NAME - 1] = 0;
	else
		dest[i] = 0; //append '\0'
}


//CP'd from Typing.c
void PokedexTypeConsolePrint(Type* obj) {
	printf("Type is ");
	switch(*obj) {
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


PokedexEntry *CopyPokedexEntry(Pokedex* table, PokedexEntry* obj) {
	printf("REACH COPY POKEDEX ENTRY\n\n");
	PokedexEntry *result = malloc(sizeof *result);

	if(result == 0) {
		GlobalDestroyer(1,0,0);
		//DestroyPokedex(table);
		exit(1);
			}
	
	result->ID = obj->ID;
	copyPokedexName(obj->name, result->name);
	result->primary = obj->primary;
	result->secondary = obj->secondary;
	result->next = 0;
	printf("FINISH COPY POKEDEXENTRY\n\n\n");
	printf("PokedexEntry address %p\n\n\n", result);
	return result;
}

//Pokedex constructor
Pokedex *NewPokedex() {
	Pokedex *result = malloc(sizeof(Pokedex));
	if(result == 0) {
		GlobalDestroyer(1,0,0);
		exit(1);
			}
	printf("Pokedex address is %p\n", result);
	result->mem = malloc(sizeof(PokedexPrivate));
	if(result->mem == 0) {
		free(result);
		GlobalDestroyer(1,0,0);
		exit(1); }
	printf("Pokedex mem address is %p\n\n\n", result->mem);
	int i;

	for(i = 0; i < MAX_POKEMON_NUMBER; i++)
		result->mem->table[i] = 0;

	return result;
}

//Put entry in table
/**
Doesn't include checking if the entry already exists. Will add another if it does.
**/
void SetPokedexEntryInPokedex(Pokedex* original, PokedexEntry* obj) {
	unsigned int hashKey = HashFunction(obj->name);
	printf("AFTER HASH: hashKey is %d\n\n", hashKey);

	if(original->mem->table[hashKey] == 0)
		original->mem->table[hashKey] = CopyPokedexEntry(original, obj);
	else {
		PokedexEntry *entryPtr = original->mem->table[hashKey];
	
		printf("INITIALIZE entryPtr\n\n");

	while(entryPtr->next != 0)
		entryPtr = entryPtr->next;

		printf("Pokedex address is %p\n", original);
		entryPtr->next = CopyPokedexEntry(original, obj);
		printf("entryPtr in SetEntry is %p\n", entryPtr);
	}
}



void ConsolePrintPokedexEntry(PokedexEntry *obj) {
	printf("Pokedex Entry #%d\n", obj->ID);
	printf("Name: %s\n", obj->name);
	printf("Primary ");
	PokedexTypeConsolePrint(&obj->primary);
	printf("Secondary ");
	PokedexTypeConsolePrint(&obj->secondary);
	 
}

//find hashkey given a name
unsigned int HashFunction(char* obj) {
	unsigned int i;
	unsigned int sum = 0;
	for(i = 0; i < MAX_NAME && obj[i] != 0; i++)
		
		sum += ((int)obj[i] * (i + 1));
	printf("hash ended at i of %u\n", i);
	sum %= MAX_POKEMON_NUMBER;
	return sum;
}

//returns 0 if names are equal
int NameComparison(char *name1, char *name2) {
	int i;
	printf("name1 is %s\n", name1);
	printf("name2 is %s\n", name2);
	for(i = 0; i < MAX_NAME && (name1[i] != 0 && name2[i] != 0); i++)
		if(name1[i] != name2[i])
			return 1;
	printf("NAME COMPARISION END PRINT\n");
	return 0;
}

void ConsolePrintPokedexEntryInPokedex(Pokedex *obj, char *name) {
	unsigned int hashKey = HashFunction(name);
	printf("obj->mem->table of %u points to %p\n", hashKey, obj->mem->table[hashKey]);
	PokedexEntry *pokePtr = obj->mem->table[hashKey];
	printf("pokedex points to %p\n", obj);
	printf("name is %s\n", name);
	printf("hash function is %u\n", hashKey);
	printf("pokePtr points to %p\n", pokePtr);
	while(pokePtr != 0 && NameComparison(pokePtr->name, name))
		pokePtr = pokePtr->next;
	if(pokePtr == 0)
		printf("ENTRY DOES NOT EXIST\n");
	else
		ConsolePrintPokedexEntry(pokePtr);
}


void DestroyPokedexEntry(PokedexEntry *recall) {
//TODO: RESET VALUES IF I FEEL LIKE IT

	free(recall);
}

void DestroyTablePointer(PokedexEntry *recall) {
	if(recall != 0) {
		DestroyTablePointer(recall->next);
		free(recall); }

}


void DestroyPokedex(Pokedex *recall) {
	int i;
	for(i = 0; i < MAX_POKEMON_NUMBER; i++) 
		DestroyTablePointer(recall->mem->table[i]);
	free(recall->mem);
	free(recall);
}

/**
#003 Venusaur Grass Poison 
#004 Charmander Fire 
**/

unsigned int GetPokedexIDFromLine(char *line, unsigned int* end) {
	unsigned int i;
	unsigned int sum = 0;

	//TODO:TEST THIS
	for(i = 1; (unsigned)(line[i] - '0') <= 9; i++) {
		sum *= 10;
		sum += (line[i] - '0');
					}
	*end = i;
	return sum;

}

 //NONE, NORMAL, GRASS, BUG, FIRE, WATER, ICE, ELECTRIC, FLYING, ROCK, GROUND, POISON, PSYCHIC, DARK, STEEL, DRAGON

Type TakeTypeFromToken(char *line) {
	int i = 0;
	switch(line[0]) {
		case 'B': return BUG;
		case 'D': 
			switch(line[1]) {
				case 'a': return DARK;
				case 'r': return DRAGON;
				}
		case 'E': return ELECTRIC;
		case 'F':
			switch(line[1]) {
				case 'i': return FIRE;
				case 'l': return FLYING;
				}
		case 'G':
			switch(line[2]) {
				case 'a': return GRASS;
				case 'o': return GROUND;
				}
		case 'I': return ICE;
		case 'N': return NORMAL;
		case 'P': switch(line[1]) {
				case 'o': return POISON;
				case 's': return PSYCHIC;
				}
		case 'S': return STEEL;
		case 'W': return WATER;
	}	
	return NONE;

}

Type TakeTypeFromLine(char *line, unsigned int *end) {
	char type[11]; //TODO:MAGIC NUM - MAX_TYPE_LEN
	unsigned int i;
	unsigned int s = *end;
	for(i = 0; i < 11 && line[i+s] != ' ' && line[i+s] != '\n'; i++) //TODO:MAGIC NUM HERE TO
		type[i] = line[i+s];
	*end = s + i;
	return TakeTypeFromToken(type);
}

void SkipSpace(char *line, unsigned int* index) {
	unsigned int i = *index;
	while(line[i] == ' ' && i < MAX_POKEDEX_LINE)
		i++;
	*index = i;
}


//inputs line taken from file and outputs a pokedex entry ready for table input.
PokedexEntry ConvertLineToPokedexEntry(char *line) {
	PokedexEntry result;

	unsigned int *i = malloc(sizeof(unsigned int));
	if( i == 0)
		GlobalDestroyer(1,0,0);
	*i = 0;
	unsigned int temp = 0;
	result.ID = GetPokedexIDFromLine(line, i); //IDretrieval
	SkipSpace(line, i);	
	
	unsigned nameTemp = *i;

	while( line[nameTemp] != ' ' && line[nameTemp] != '\n' && temp < MAX_NAME) { 	
		result.name[temp] = line[nameTemp]; //Name retrieval
		temp++;
		nameTemp++; }
	result.name[temp] = 0;
	*i = nameTemp;

	SkipSpace(line, i);	
	result.primary = TakeTypeFromLine(line, i);

	if( line[*i] == '\n') {
		result.secondary = NONE;
	}
	else {
		SkipSpace(line, i);
		result.secondary = TakeTypeFromLine(line, i);
	}
	free(i);
	return result;

}

/**
inputs file into Pokedex

**/
void FillPokedex(Pokedex *dexter, char *fileName) {
	FILE *inputFile = fopen(fileName, "r");
	if(inputFile == 0) {
		printf("Opening inputFile of %s failed.", fileName);
		GlobalDestroyer(1,0,0);
		exit(1);
	}
	char line[MAX_POKEDEX_LINE];
	int max;
	PokedexEntry tempEntry;
	while( fgets(line, MAX_POKEDEX_LINE - 1,inputFile) != 0) {
		
		tempEntry = ConvertLineToPokedexEntry(line);
		SetPokedexEntryInPokedex(dexter, &tempEntry);
	
	} 
	fclose(inputFile);
}











