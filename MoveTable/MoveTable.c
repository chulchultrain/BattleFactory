#include <SpecialConstants/SpecialConstants.h>
#include <BF_Special_Util/Special_Util.h>
#include <stdio.h>
#include <stdlib.h>


/*
struct MoveTablePrivate {

*

};
*/

/*
12_26_2015 - Only need moveID and name, so won't use Pentry move type, just unsigned int + char array
*/
/*
typedef struct MoveHashTable {
	
	unsigned int ID[MAX_MOVE_NUMBER];
} MoveHashTable;


MoveHashTable *StaticMoveNameArray() {
	static char moveName[MAX_MOVE_NUMBER][MAX_NAME];
	static unsigned int flag = 0;
	if(flag == 0) {
	//initialize table
	
	flag = 1;
	}


}
*/

void GetMoveNameFromID(unsigned int ID, char *dest, unsigned int dest_limit) {

	static char moveNames[MAX_MOVE_NUMBER][MAX_NAME];
	static unsigned int flag = 0;

	if(flag == 0) {
		unsigned int i,j;
		for(i = 0; i < MAX_MOVE_NUMBER; i++) {
			char id[MAX_NAME] = {0};
			char idFileName[MAX_FILE_NAME] = MOVES_DIRECTORY;
			char buffer[MAX_NAME] = {0};
			UnsignedIntToString(i+1,id,MAX_NAME);
			AppendArrayToArray(id,MAX_NAME,idFileName,MAX_FILE_NAME);
			FILE *fin = fopen(idFileName,"r");
			fgets(buffer,MAX_NAME,fin);
			fgets(moveNames[i],MAX_NAME,fin);
			fclose(fin);
		}
	flag = 1;
	}
	unsigned int k = 0;
	for(k = 0; k < dest_limit && k < MAX_NAME && moveNames[ID][k] != 0; k++) {
		dest[k] = moveNames[ID-1][k];
		}

}
