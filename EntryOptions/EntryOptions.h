#ifndef __ENTRYOPTIONS_H_INCLUDED__
#define __ENTRYOPTIONS_H_INCLUDED__

#include <SpecialConstants/SpecialConstants.h>

typedef struct EntryOptions {
	char name[MAX_NAME];
	unsigned int region;
	unsigned int choice;
	unsigned int IV;
	unsigned int level;
} EntryOptions;

EntryOptions DefaultOptions(unsigned int optionChoice, void *choiceSet);

void ConsolePrintOptions(EntryOptions options);
#endif
