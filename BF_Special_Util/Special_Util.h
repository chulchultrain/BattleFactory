#ifndef __SPECIAL_UTIL_H_INCLUDED__
#define __SPECIAL_UTIL_H_INCLUDED__

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

//Making the Directory. Just Make a struct stat *st pointer and malloc and then use it in the function. That's all.
void MakeDir(char *dirName, struct stat *st);


/**
Attempts to translate a string(char array) to an unsigned int.
@param line - string(char array) to be translated
@param line_length - length of string to be translated to ensure memory access doesn't go beyond the limits
Will attempt to return an unsigned int based on the digits present in the char array. If the char array is invalid, meaning
it contains items other than numerical digits, the function will fail. When failing, function will return 1 and the unsigned int
will be set to 0. 

Successful call will return 0, and set pointer properly.
**/
unsigned int StringToUnsignedInt(char *line, unsigned int line_length, unsigned int *);

//start = start index in the destination array. This function will always try to put the full src array into an index of the dest array.
unsigned int InsertArrayInArray(char *src, unsigned int srcLimit, char *dest, unsigned int start, unsigned int destLimit);

//appends full array to another array. aka index 0 to first occurence of NULL, then index 0 
unsigned int AppendArrayToArray(char *src, unsigned int srcLimit, char *dest, unsigned int destLimit);

//same thing as fgets. However, if it fails, then it calls the global destroyer.if safeDestruct flag is set.
void SafeReadLine(char *line, unsigned int limit, FILE *fptr,unsigned int safeDestruct);

#endif
