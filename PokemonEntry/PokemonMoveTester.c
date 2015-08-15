#include <PokemonEntry/PokemonMove.h>

#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_MOVE_NAME
#define MAX_MOVE_NAME 21
#endif

int main() {

PokemonMove *hyperBeam = NewPokemonMove();

char w[100] = "WHIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII";
	printf("1st\n");
hyperBeam->SetName(hyperBeam,w);
	printf("2nd\n");
hyperBeam->ConsolePrint(hyperBeam);
	printf("3rd\n");


return 0;
}
