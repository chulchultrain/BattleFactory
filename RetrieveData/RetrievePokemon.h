#ifndef __RETRIEVEPOKEMON_H_INCLUDED__
#define __RETRIEVEPOKEMON_H_INCLUDED__


#include <PokemonEntry/PokemonEntry.h>
#include <stdio.h>


//assumes IV = 0 and level = 100
void ConsolePrintForPokemon(char *name);

void ConsolePrintEntryList(char *name,unsigned int region);

PokemonEntry *NewEntryFromNameChoice(char *name, unsigned int choice);

PokemonEntry *NewEntryFromData(char *name, unsigned int region, unsigned int choice, unsigned int IV, unsigned int level);

void SetEntryFromNameChoice(PokemonEntry *entry, char *name, unsigned int choice);

void SetEntryWithData(PokemonEntry *entry, char *name, unsigned int region, unsigned int choice, unsigned int IV, unsigned int level);


#endif
