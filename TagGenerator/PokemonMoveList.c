
#include <TagGenerator/PokemonMoveList.h>
#include <PokemonEntry/PokemonMove.h>

/*
Data structure to hold info about move
*/
typedef struct MoveData {
    unsigned int index;
    char name[MAX_NAME];
    unsigned int damage;
    Type moveType;
    MoveCategory moveCat;
} MoveData;

/*
private part to provide encapsulation.
*/
typedef struct PokemonMoveListPrivate {
    MoveData moves[MAX_MOVES]
    
} PokemonMoveListPrivate;

/*
Zero out moveData struct.
*/
void ResetMove(MoveData *m) {
    m->index = 0;
    int i;
    for(i = 0; i < MAX_NAME; i++)
        name[i] = 0;
    damage = 0;
    moveType = 0;
    moveCat = 0;
}

/*
Initializes PML memory
*/
void SetPokemonMoveListMemory(PokemonMoveListPrivate *memPtr) {
    if(memPtr != 0) {
        int i;
        for(i = 0; i < MAX_MOVES; i++) 
            ResetMove(memPtr->moves[i]);
    }
}

PokemonMoveList *NewPokemonMoveList() {
    PokemonMoveList *moveListPtr = malloc(sizeof(PokemonMoveList));
    if(moveListPtr == 0) { //malloc failure
        GlobalDestroyer(1,0,0);
    }
    
    GlobalDestroyer(0,moveListPtr,POKEMONMOVELIST); //TODO:ADD POKEMONMOVELIST to GlobalDestroyer
    
    moveListPtr->mem = malloc(sizeof(PokemonMoveListPrivate));
    if(moveListPtr->mem == 0) {
        GlobalDestroyer(1,0,0);
    }
    SetPokemonMoveListMemory(moveListPtr->mem);
    
    //initialize function pointers
    //initialize array of moves.

}
