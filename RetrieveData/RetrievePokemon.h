#ifndef __RETRIEVEPOKEMON_H_INCLUDED__
#define __RETRIEVEPOKEMON_H_INCLUDED__


#include <PokemonEntry/PokemonEntry.h>
#include <stdio.h>

/**First Basic Function
Console Print all entries of the Pokemon desired.
**/
void ConsolePrintPokemonEntryFile(FILE *fPtr);

PokemonEntry *EntryFromNameChoice(char *name, unsigned int choice);

void TopLevel(char *name);

#endif
