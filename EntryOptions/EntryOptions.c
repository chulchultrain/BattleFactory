
#include <EntryOptions/EntryOptions.h>

#ifndef DEFAULT_LEVEL



EntryOptions DefaultOptions(unsigned int optionChoice, void *choiceSet) {
	static EntryOptions defaultOptions;
	
	switch(optionChoice) {
		case 1:  //name
			CopyName( (char *)choiceSet, defaultOptions.name);
		case 2: //region
			defaultOptions.region = *(unsigned int *)choiceSet;
			break;
		case 3: //choice
			defaultOptions.choice = *(unsigned int *)choiceSet;
			break;
		case 4: //IV
			defaultOptions.IV = *(unsigned int *)choiceSet;
			break;
		case 5: //level
			defaultOptions.level = *(unsigned int *)choiceSet;
			break;
	}



	return defaultOptions;

}
