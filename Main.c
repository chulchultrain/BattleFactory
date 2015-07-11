#include <stdio.h>
#include <stdlib.h>
#include "PokemonEntry.h"
//TODO:CHANGE BACK TO POKEMONENTRY

int main() {
int *a, *b, *c, *d, *e, *f;
a = malloc(sizeof(int));
b = malloc(sizeof(int));
c = malloc(sizeof(int));
d = malloc(sizeof(int));
e = malloc(sizeof(int));
f = malloc(sizeof(int));
*a = 10;
*b = 11;
*c = 12;
*d = 13;
*e = 14;
*f = 15;

Type *alpha = malloc(sizeof(Type));
*alpha = NONE;
Type *beta = malloc(sizeof(Type));
*beta = DARK;
/**
TypeContainer *result = NewTypeContainer();
result->SetPrimary(result, alpha);
result->SetSecondary(result, beta);
result->ConsolePrint(result);
DeleteTypeContainer(result);
**/
/**
PokemonStats *result = NewPokemonStats();
result->SetHP(result, a);
result->SetA(result, b);
result->SetD(result, c);
result->SetSpA(result, d);
result->SetSpD(result, e);
result->SetS(result, f);
result->ConsolePrint(result);

**/

PokemonEntry *result = NewPokemonEntry();
result->SetHitPoints(result, a);
result->SetAttack(result, b);
result->SetDefense(result, c);
result->SetSpecialAttack(result, d);
result->SetSpecialDefense(result, e);
result->SetSpeed(result, f);
result->SetPrimaryType(result, alpha);
result->SetSecondaryType(result, beta);
result->ConsolePrint(result);
DeletePokemonEntry(result);

free(a);
free(b);
free(c);
free(d);
free(e);
free(f);
free(alpha);
free(beta);

return 0;
}
