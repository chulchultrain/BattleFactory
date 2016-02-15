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
set->SetMoveName(set,0,d);
set->SetMoveDamage(set,0,100);
set->SetMoveCategory(set,0,PHYSICAL);
set->SetMoveDamage(set,6,100);
	printf("2nd\n");

set->ConsolePrint(set);
	printf("3rd\n");
DeletePokemonMoveSet(set);

return 0;
}
