#include <TagGenerator/FillDataFiles.h>
#include <BF_Special_Util/Special_Util.h>
#include <stdlib.h>
#include <stdio.h>
#include <SpecialConstants/SpecialConstants.h>





void WriteNameTagFile(FILE *entryFilePtr, char *nameDir, char *entryName, char *region, struct stat *st) {
	char outputFileName[MAX_FILE_NAME] = {0};
	unsigned int i = 0;
	i = InsertArrayInArray(nameDir, MAX_FILE_NAME, outputFileName, i, MAX_FILE_NAME);

	AppendArrayToArray(region, MAX_REGION_SUBDIR_LENGTH, outputFileName, MAX_FILE_NAME);

	i = InsertArrayInArray(entryName, MAX_NAME, outputFileName, i, MAX_FILE_NAME);

	

	printf("%s\n", outputFileName);
	FILE *outputFile = fopen(outputFileName, "a");
	if( outputFile != 0) {

		char buffer[MAX_CHAR_BUFFER_SIZE] = {0};
		if( fgets(buffer, MAX_CHAR_BUFFER_SIZE, entryFilePtr) == 0)	
			return;
	
		while( buffer[0] != '\n' ) {
			fprintf(outputFile, "%s", buffer);
			fgets(buffer, MAX_CHAR_BUFFER_SIZE, entryFilePtr); 
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

void FillNameTagFiles(char *nameDir, char *entryFileName, char *region) {
	struct stat *st = malloc(sizeof(struct stat));
	
	//for every entry in ur entryfile, put it in the correct outputfile. Must append. 
	printf("%s\n", entryFileName);
	
	FILE *entryFilePtr = fopen(entryFileName,"r");
	if(entryFilePtr != 0) {
	char name[MAX_NAME];
	
	while ( fgets(name, MAX_NAME, entryFilePtr) != 0) {
		RidOfNewLine(name, MAX_NAME);
		WriteNameTagFile(entryFilePtr, nameDir, name, region,st);
	}

	fclose(entryFilePtr);
	}
	else {
		printf("Open file failure\n");
		exit(1);
	}

}

