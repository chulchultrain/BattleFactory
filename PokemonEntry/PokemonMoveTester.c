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
set->SetMove(set,1,a);
	printf("2nd\n");
set->SetMove(set,2,b);
set->SetMove(set,3,c);
set->SetMove(set,4,d);
set->ConsolePrint(set);
	printf("3rd\n");
DeletePokemonMoveSet(set);

return 0;
}
