#include <PokemonEntry/PokemonMoveSet.h>

#include <stdio.h>
#include <stdlib.h>


int main() {

PokemonMoveSet *set = NewPokemonMoveSet();

char a[100] = "";
char b[100] = "Hyper Beam";
char c[100] = "Solar Rage";
char d[100] = "DESTRUCTION";
	printf("1st\n");
set->SetFirstMove(set,a);
	printf("2nd\n");
set->SetSecondMove(set,b);
set->SetThirdMove(set,c);
set->SetFourthMove(set,d);
set->ConsolePrint(set);
	printf("3rd\n");
DeletePokemonMoveSet(set);

return 0;
}
