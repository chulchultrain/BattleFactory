#include <GlobalDestroyer/GlobalDestroyer.h>

/*
Stores data on every pokemon move. Indexed by the actual index of the move.
TODO: Make an entry in GlobalDestroyer for this kind of data structure.
*/


typedef struct PokemonMoveList {

/*
@Method - SetPokemonMoveFromIndex(PokemonEntry *ptr, int moveIndex, int entryMoveNum) 
Initializes the PokemonEntry's move based on the move index and which move number we want to initialize.
*/
void (*SetPokemonMoveFromIndex)(); //PokemonEntry ptr, int actual move Index, int which move of entry 


} PokemonMoveArray;

/*
On success, this function returns an initialized data structure which contains data on all pokemon moves that are currently on file.
and initialize the function pointers.

On failure, this function will call the GlobalDestroyer.
*/
PokemonMoveList *NewPokemonMoveList();


/*
Deletes the PokemonMoveList data structure to prevent memory leaks. This method should not be explicitly be called 
by your Top Level program. The GlobalDestroyer will call this.
*/
void *DeletePokemonMoveList(PokemonMoveList *recall);
