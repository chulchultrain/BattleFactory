#include <TagGenerator/FillDataFiles.h>
#include <BF_Special_Util/Special_Util.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MAX_NAME 
#define MAX_NAME 21
#endif

#ifndef MAX_DIR_NAME
#define MAX_DIR_NAME 1000
#endif



void WriteNameTagFile(FILE *entryFilePtr, char *nameDir, char *entryName, struct stat *st) {
	char outputFileName[MAX_DIR_NAME] = {0};
	unsigned int i = 0;
	i = InsertArrayInArray(nameDir, MAX_DIR_NAME, outputFileName, i, MAX_DIR_NAME);

	i = InsertArrayInArray(entryName, MAX_NAME, outputFileName, i, MAX_DIR_NAME);

	printf("%s\n", outputFileName);
	FILE *outputFile = fopen(outputFileName, "a");
	if( outputFile != 0) {

		char buffer[80] = {0};
		if( fgets(buffer, 80, entryFilePtr) == 0)	
			return;
	
		while( buffer[0] != '\n' ) {
			fprintf(outputFile, "%s", buffer);
			fgets(buffer, 80, entryFilePtr); 
		}
		fprintf(outputFile,"\n");
		fclose(outputFile);
		return;
		}
	printf("FileAppend Failed\n");
}

void RidOfNewLine(char *name, unsigned int nameLimit) {
	unsigned int i = 0;
	while(name[i] != 0 && i < nameLimit)
		i += 1;
	if(i > 0)
		if(name[i-1] == '\n')
			name[i-1] = 0;
		
}

void FillNameTagFiles(char *nameDir, char *entryFileName) {
	struct stat *st = malloc(sizeof(struct stat));
	
	//for every entry in ur entryfile, put it in the correct outputfile. Must append. 
	printf("%s\n", entryFileName);
	
	FILE *entryFilePtr = fopen(entryFileName,"r");
	if(entryFilePtr != 0) {
	char name[MAX_NAME];
	
	while ( fgets(name, MAX_NAME, entryFilePtr) != 0) {
		RidOfNewLine(name, MAX_NAME);
		WriteNameTagFile(entryFilePtr, nameDir, name, st);
	}

	fclose(entryFilePtr);
	}
	else
		exit(1);
	

}

