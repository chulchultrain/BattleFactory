#include <stdio.h>
#include <stdlib.h>
#include <MoveTable/MoveTable.h>
#include <GlobalDestroyer/GlobalDestroyer.h>
#include <SpecialConstants/SpecialConstants.h>



int main() {

	unsigned int i = 2;
	char name[MAX_NAME] = {0};
	GetMoveNameFromID(i,name,MAX_NAME);
	printf("name of move %d is %s\n",i,name);


	GlobalDestroyer(1,0,0);
	return 0;
}
