
#include <TagGenerator/PokemonMoveList.h>



PokemonMoveList *NewPokemonMoveList() {
    PokemonMoveList *moveListPtr = malloc(sizeof(PokemonMostList));
    if(moveListPtr == 0) { //malloc failure
        GlobalDestroyer(1,0,0);
    }
    //initialize function pointers
    //initialize array of moves.

}
