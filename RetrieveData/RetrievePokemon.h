#ifndef __RETRIEVEPOKEMON_H_INCLUDED__
#define __RETRIEVEPOKEMON_H_INCLUDED__


#include <PokemonEntry/PokemonEntry.h>
#include <EntryOptions/EntryOptions.h>
#include <stdio.h>


/*
Given a pokemon name and the region that the pokemon comes from, 
this function prints the list of the information about the entries for that pokemon to stdout.

char *name: name of pokemon
unsigned int region: the region the entry comes from
*/
void ConsolePrintEntryList(char *name,unsigned int region);

void ConsolePrintPokemonEntryFile(EntryOptions options);

//TODO void FilePrintEntryList(char *name, unsigned int region, FILE *fout);


/*
DEPRECATED: it was just not modular enough.
Given the name of the pokemon, and the choice of the entry in the entry file, 
user will be prompted in stdout to input the region into stdin. 
Based on that information and assuming level = 100 and IV = 0, function will generate a fully loaded PokemonEntry structure
with the correct information.

char *name - name of pokemon
choice - choice of entry in the entry file.
*/
PokemonEntry *NewEntryFromNameChoice(char *name, unsigned int choice);


/*
Given information of the entry, function will create a fully loaded PokemonEntry structure reflecting the entry information.
Then, return a pointer to it.

char *name: name of pokemon
unsigned int region: region of entry
unsigned int choice: choice of entry in the entry file.
unsigned int IV: number of IVs the pokemon has
unsigned int level: level of pokemon
*/
PokemonEntry *NewEntryFromData(EntryOptions options);

/*
DEPRECATED: not modular enough.
Given the name of the pokemon, and the choice of the entry in the entry file, 
user will be prompted in stdout to input the region into stdin. 
Based on that information and assuming level = 100 and IV = 0, function will set an already existing PokemonEntry structure to reflect the entry information.

PokemonEntry *entry: poitner to already existing PokemonEntry structure
char *name - name of pokemon
choice - choice of entry in the entry file.
*/
void SetEntryFromNameChoice(PokemonEntry *entry, char *name, unsigned int choice);

/*
Given information of the entry, function will set an already existing PokemonEntry structure to reflect the entry information.

PokemonEntry *entry: pointer to already existing PokemonEntry structure
char *name: name of pokemon
unsigned int region: region of entry
unsigned int choice: choice of entry in the entry file.
unsigned int IV: number of IVs the pokemon has
unsigned int level: level of pokemon
*/
void SetEntryWithData(PokemonEntry *entry, EntryOptions options);


#endif
