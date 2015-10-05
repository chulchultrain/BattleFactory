#include <BF_Special_Util/Special_Util.h>
#include <stdlib.h>
#include <stdio.h>


unsigned int StringToUnsignedInt(char *line, unsigned int line_length, unsigned int *product) {
	unsigned int temp = 0;
	unsigned int i;
	for(i = 0;  i < line_length && line[i] != '\n'; i++) {
		if( line[i] >= '0' && line[i] <= '9') {
			temp *= 10;
			temp += (line[i] - '0'); 
			printf("unsigned int is %u\n", temp);
				}
		else
			return 1;

	}
	*product = temp;
	printf("unsigned int is %u\n", *product);


	return 0;
}

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

unsigned int AppendArrayToArray(char *src, unsigned int srcLimit, char *dest, unsigned int destLimit) {
	unsigned int i = 0; //destArray iterator
	unsigned int j = 0; //srcArray iterator
	
	//iterate through destarray until reach its end.
	while( i < destLimit && dest[i] != 0)
		i++;

	//if no space to append, return
	if( i == destLimit)
		return destLimit;


	//append as much as can without going over destLimit.
	while(i < destLimit && src[j] != 0) {
		dest[i] = src[j];
		i++;
		j++; }

	return i;

}
