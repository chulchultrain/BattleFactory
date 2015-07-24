#include "Pokedex.h"

#include <stdlib.h>
#include <stdio.h>

struct PokedexPrivate {
	PokedexEntry *table[MAX_POKEMON_NUMBER];

};

PokedexEntry *CopyPokedexEntry(PokedexEntry *obj);

/**
unsigned int ID;
char name[MAX_NAME];
Type primary;
Type secondary;
**/

//CP'd from PokemonEntry.c
void copyName(const char* source, char* dest) {
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

PokedexEntry *CopyPokedexEntry(PokedexEntry *obj) {
	PokedexEntry *result = malloc(sizeof *result);
	result->ID = obj->ID;
	copyName(obj->name, result->name);
	result->primary = obj->primary;
	result->secondary = obj->secondary;
	return result;
}

//Pokedex constructor
Pokedex *NewPokedex() {
	Pokedex *result = malloc(sizeof *result);
	result->mem = malloc(sizeof *result->mem);
	
}

//Put entry in table
void SetPokedexEntryInPokedex(Pokedex *original, PokedexEntry *obj) {
	original->mem->table[obj->ID] = CopyPokedexEntry(obj);
}

void ConsolePrintPokedexEntry(PokedexEntry *obj) {
	printf("Pokedex Entry #%d\n", obj->ID);
	printf("Name: %s\n", obj->name);
	printf("Primary ");
	TypeConsolePrint(&obj->primary);
	printf("Secondary ");
	TypeConsolePrint(&obj->secondary);
	 
}

void ConsolePrintPokedexEntryInPokedex(Pokedex *obj, unsigned int ID) {
	PokedexEntry *pokePtr = obj->mem->table[ID];
	ConsolePrintPokedexEntry(pokePtr);
}

void DestroyPokedexEntry(PokedexEntry *recall) {
//TODO: RESET VALUES IF I FEEL LIKE IT
	free(recall);
}

void DestroyPokedex(Pokedex *recall) {
	int i;
	for(i = 0; i < MAX_POKEMON_NUMBER; i++) 
		DestroyPokedexEntry(recall->mem->table[i]);
	free(recall->mem);
	free(recall);
}













