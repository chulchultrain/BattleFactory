#ifndef __ENTRYOPTIONS_H_INCLUDED__
#define __ENTRYOPTIONS_H_INCLUDED__



typedef struct EntryOptions {
	char name[21];
	unsigned int region;
	unsigned int choice;
	unsigned int IV;
	unsigned int level;
} EntryOptions;

EntryOptions DefaultOptions(unsigned int optionChoice, void *choiceSet);


#endif
