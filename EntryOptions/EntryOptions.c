
#include <EntryOptions/EntryOptions.h>
#include <stdio.h>

EntryOptions DefaultOptions(unsigned int optionChoice, void *choiceSet) {
	static EntryOptions defaultOptions = { "Abra", 1, 0 , 0, 100};
	unsigned int i = 0;
	switch(optionChoice) {
		case 1:  //name
			for(i = 0; i < MAX_NAME; i++)
				defaultOptions.name[i] = ((char *)choiceSet)[i];
			break;
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



void ConsolePrintOptions(EntryOptions options) {
	printf("%s\n%u\n%u\n%u\n%u\n",options.name,options.region,options.choice,options.IV,options.level);

}
