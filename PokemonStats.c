#include "PokemonStats.h"
#include <stdlib.h>

PokemonStats* NewPokemonStats() {
	PokemonStats *pokeStats = malloc(sizeof(PokemonStats));
	pokeStats->HitPoints = 0;
	pokeStats->Attack = 0;
	pokeStats->Defense = 0;
	pokeStats->SpecialAttack = 0;
	pokeStats->SpecialDefense = 0;
	pokeStats->Speed = 0;

	return pokeStats;

}
