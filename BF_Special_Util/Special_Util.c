#include <BF_Special_Util/Special_Util.h>
#include <SpecialConstants/SpecialConstants.h>
#include <stdlib.h>


unsigned int StringEquality(char *str1, char *str2) {
	unsigned int i = 0;
	while( str1[i] == str2[i] && str1[i] != 0)
		i++;

	if( str1[i] != str2[i]) 
		return 0;
	else 
		return 1; 

}



void copyName(const char* source, char* dest) {
	int i = 0;
	while(i < MAX_NAME && source[i] != 0) {
		dest[i] = source[i];
		i++;
	}
	if(i == MAX_NAME) //took up all the space so must truncate for'\0'
		dest[MAX_NAME - 1] = 0;
	else
		dest[i] = 0; //append '\0'
}

unsigned int copyString(const char* src, unsigned int src_limit, char* dest, unsigned int dest_limit) {
	unsigned int i = 0, maxL = 0;
	if(dest_limit > src_limit)
		maxL = dest_limit;
	else
		maxL = src_limit;
	for(i = 0; i < maxL; i++) {
		dest[i] = src[i];
		if(dest[i] == 0)
			break;
	}
	return 0;
}	

unsigned int StringToUnsignedInt(char *line, unsigned int line_length, unsigned int *product) {
	unsigned int temp = 0;
	unsigned int i;
	for(i = 0;  i < line_length && line[i] != 0 && line[i] != '\n'; i++) {
		if( line[i] >= '0' && line[i] <= '9') {
			temp *= 10;
			temp += (line[i] - '0'); 
		//	printf("unsigned int is %u\n", temp);
				}
		else {
			*product = 0;	
			return 1;
			}

	}
	*product = temp;
	//printf("unsigned int is %u\n", *product);


	return 0;
}


unsigned int UnsignedIntToString(unsigned int num, char *line, unsigned int limit) {
	unsigned int len = 0;
	unsigned int tempNum = num;
	char temp[MAX_LINE_LENGTH] = {0};
	for(len = 0; len < limit && tempNum > 0;len++) {
		temp[len] = tempNum % 10;
//		printf("%u \n\n",temp[len]);
		tempNum /= 10;

	}
//	printf("%u\n\n",len);
	if(tempNum > 0) {
		return 1;
	}

	len--;
	//not working reverses digits
	unsigned int i;
	for(i = 0; i <= len; i++) {
		//printf("%c %u \n\n",line[len],len);
		line[i] = (temp[len - i] + 48);
	}
	if( i < limit - 1) 
		line[i] = 0;
	else
		line[limit - 1] = 0;
//	line[len] = (temp[len] + 48);
//	printf("%s\n\n",line);

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

//TODO:FIX up errorcode
unsigned int InsertArrayInArray(char *src, unsigned int srcLimit, char *dest, unsigned int start, unsigned int destLimit) {
	unsigned int i = 0;
	

	for(i = 0; (i + start) < destLimit && i < srcLimit && src[i] != 0; i++)
		dest[i + start] = src[i];
	if( (i + start) < (destLimit - 1) )
		dest[i + start] = 0;
	else
		dest[destLimit - 1] = 0;

	return i + start;

}

//TODO: FIX up errorcode
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
	if( i < destLimit - 1) 
		dest[i] = 0;
	else
		dest[destLimit - 1] = 0;

	return i;

}



void SafeReadLine(char *line, unsigned int limit, FILE *fin,unsigned int safeDestruct) {
	if(safeDestruct) {
		if( fgets(line, limit, fin) == 0) {
			GlobalDestroyer(1,0,0); 
						}

	}
	else {
		fgets(line,limit,fin);
	}

}

//RNL stands for remove everything after new line
void SafeReadLineRNL(char *line, unsigned int limit, FILE *fin,unsigned int safeDestruct) {
	if(safeDestruct) {
		if( fgets(line, limit, fin) == 0) {
			GlobalDestroyer(1,0,0); 
						}
		else {
			int i = 0;
			for(i = 0; i < limit; i++) {
				if(line[i] == '\n') {
					line[i] = 0;
					break;
					}	
			}	
		}

	}
	else {
		fgets(line,limit,fin);
		int i = 0;
		for(i = 0; i < limit; i++) {
			if(line[i] == '\n') {
				line[i] = 0;
				break;
				}
		}
	}

}

unsigned int CorrectRegionPrompt(char *entryFileDir, unsigned int fileDirLimit) {
	
	static char EMERALD_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_EMERALD;
	static char DPP_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_DPP;
	static char HGSS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_HGSS;
	static char BW_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW;
	static char BW2_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW2;
	static char XY_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_XY;
	static char ORAS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_ORAS;
	static char *regionPointer[MAX_REGIONS] = {EMERALD_R, DPP_R, HGSS_R, BW_R, BW2_R, XY_R, ORAS_R};

	printf("Choose which game by typing an integer\n");
	unsigned int i;

	for(i = 0; i < MAX_REGIONS && regionPointer[i] != 0; i++)
		printf("%s - %u\n", regionPointer[i], i);	

	char buffer[MAX_LINE_LENGTH];
	unsigned int uPtr[1];	

	fgets(buffer,MAX_LINE_LENGTH,stdin);
	if( !StringToUnsignedInt(buffer, MAX_LINE_LENGTH, uPtr) ) {
		AppendArrayToArray( *(regionPointer + uPtr[0]), MAX_REGION_SUBDIR_LENGTH, entryFileDir, fileDirLimit);
		return 0; }
	else 
		return 1; // something idk maybe an error msg. maybe return function shoudl also error 0,1

}

//TODO:ADD the regions + their index chocie to a documentto a document
unsigned int AppendRegionToString(unsigned int regionChoice, char *str, unsigned int strLimit) {

	static char EMERALD_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_EMERALD;
	static char DPP_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_DPP;
	static char HGSS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_HGSS;
	static char BW_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW;
	static char BW2_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW2;
	static char XY_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_XY;
	static char ORAS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_ORAS;
	static char *regionPointer[MAX_REGIONS] = {EMERALD_R, DPP_R, HGSS_R, BW_R, BW2_R, XY_R, ORAS_R};

	

	if( regionChoice < MAX_REGIONS && regionPointer[regionChoice] != 0)
		return AppendArrayToArray( *(regionPointer + regionChoice), MAX_REGION_SUBDIR_LENGTH, str, strLimit);
	else
		return 1;

}

unsigned int RegionFromConsoleInput(unsigned int *choice) {

	static char EMERALD_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_EMERALD;
	static char DPP_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_DPP;
	static char HGSS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_HGSS;
	static char BW_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW;
	static char BW2_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW2;
	static char XY_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_XY;
	static char ORAS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_ORAS;
	static char *regionPointer[MAX_REGIONS] = {EMERALD_R, DPP_R, HGSS_R, BW_R, BW2_R, XY_R, ORAS_R};

	printf("Choose which game by typing an integer\n");
	unsigned int i;

	for(i = 0; i < MAX_REGIONS && regionPointer[i] != 0; i++)
		printf("%s - %u\n", regionPointer[i], i);			

	char buffer[MAX_LINE_LENGTH];

	fgets(buffer,MAX_LINE_LENGTH,stdin);
	return StringToUnsignedInt(buffer, MAX_LINE_LENGTH, choice);
	

}

unsigned int RegionFromFileInput(unsigned int *choice, FILE *fin) {
/**
	static char EMERALD_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_EMERALD;
	static char DPP_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_DPP;
	static char HGSS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_HGSS;
	static char BW_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW;
	static char BW2_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_BW2;
	static char XY_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_XY;
	static char ORAS_R[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_ORAS;
	static char *regionPointer[MAX_REGIONS] = {EMERALD_R, DPP_R, HGSS_R, BW_R, BW2_R, XY_R, ORAS_R};
**/

	char buffer[MAX_LINE_LENGTH];

	fgets(buffer,MAX_LINE_LENGTH,fin);
	return StringToUnsignedInt(buffer, MAX_LINE_LENGTH, choice);
	

}

unsigned int CalcNonHPStat(unsigned int base, unsigned int EV, unsigned int IV, unsigned int level) {
	unsigned int val = 2 * base + IV + (EV / 4);
	val *= level;
	val /= 100; 
	val += 5;
//	printf("print stat %u\n",val);
	return val;
}

unsigned int CalcHPStat(unsigned int base, unsigned int EV, unsigned int IV, unsigned int level) {
	unsigned int val = 2 * base + IV + (EV / 4);
	val *= level;
	val /= 100; 
	val += (level + 10);
//	printf("print hp %u\n",val);
	return val;
}






