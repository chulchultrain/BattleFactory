#ifndef __SPECIAL_UTIL_H_INCLUDED__
#define __SPECIAL_UTIL_H_INCLUDED__

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//Making the Directory. Just Make a struct stat *st pointer and malloc and then use it in the function. That's all.
void MakeDir(char *dirName, struct stat *st);


//start = start index in the destination array. This function will always try to put the full src array into an index of the dest array.
unsigned int InsertArrayInArray(char *src, unsigned int srcLimit, char *dest, unsigned int start, unsigned int destLimit);

//appends full array to another array. aka index 0 to first occurence of NULL, then index 0 
unsigned int AppendArrayToArray(char *src, unsigned int srcLimit, char *dest, unsigned int destLimit);

#endif
