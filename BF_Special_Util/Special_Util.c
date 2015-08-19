#include <BF_Special_Util/Special_Util.h>
#include <stdlib.h>
#include <stdio.h>



void MakeDir(char *dirName, struct stat *st) {
	if(dirName != 0 && st != 0) {
		if (stat(dirName, st) == -1) 
 	   		mkdir(dirName, 0700);
		else
			printf("%s directory already exists\n", dirName);
	}
}


unsigned int InsertArrayInArray(char *src, unsigned int srcLimit, char *dest, unsigned int start, unsigned int destLimit) {
	unsigned int i = 0;
	

	for(i = 0; (i + start) < destLimit && i < srcLimit && src[i] != 0; i++)
		dest[i + start] = src[i];


	return i + start;

}
