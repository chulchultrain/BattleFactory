#include <stdlib.h>
#include <stdio.h>

#include <PokemonEntry/PokemonEntryTestDriver.h>
#include <PokemonEntry/PokemonEntry.h>
#include <PokemonEntry/Typing.h>
#include <PokemonEntry/PokemonMove.h>


/**
Test driver to see whether PokemonEntry and all its components work togethere properly.

TestCases: 
Name: Actual name, 1 char name,  Empty String, String w/ len > MAX_NAME.

Stats: 0, negative value, positive value, 2^32 - 1,
NOPE Dont have to do this made them all unsigned ints

Type: All Types

Test: 
New Constructor and Copy Constructor.





**/



void PETest(unsigned int *HP, unsigned int *A, unsigned int *D, unsigned int *SpA, unsigned int *SpD, unsigned int *S, Type *t1, Type *t2, char* name, char *m1, char *m2, char *m3, char *m4, MoveCategory *m) {
PokemonEntry *result = NewPokemonEntry();
printf("BEFORENAME\n\n\n\n");
printf("name is %s\n", name);
result->SetName(result, name);
printf("AFTERNAME\n\n\n\n");
result->SetHitPoints(result, HP);
result->SetAttack(result, A);
result->SetDefense(result, D);
result->SetSpecialAttack(result, SpA);
result->SetSpecialDefense(result, SpD);
result->SetSpeed(result, S);
result->SetPrimaryType(result, t1);
result->SetSecondaryType(result, t2);
result->SetFirstMove(result, m1,S,t1,m);
result->SetSecondMove(result, m2,D,t2,m);
result->SetThirdMove(result, m3,A,t1,m);
result->SetFourthMove(result, m4,SpA,t2,m);
result->ConsolePrint(result);
}




int main() {
	char overFlowName[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char emptyName[30] = "";
	char oneName[30] = "a";

	char move1[30] = "Hyper Beam";
	char move2[30] = "Flex";
	char move3[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char move4[30] = "";

	MoveCategory *moveCat = malloc(sizeof(MoveCategory));
	*moveCat = PHYSICAL;

	Type *t1 = malloc(sizeof(Type));
	*t1 = NONE;
	Type *t2 = malloc(sizeof(Type));
	*t2 = DRAGON;
	unsigned int *hp = malloc(sizeof(unsigned int));
	*hp = 1;
	unsigned int *a = malloc(sizeof(unsigned int));
	*a = 2;
	unsigned int *d = malloc(sizeof(unsigned int));
	*d = 3;
	unsigned int *SpA = malloc(sizeof(unsigned int));
	*SpA = 4;
	unsigned int *SpD = malloc(sizeof(unsigned int));
	*SpD = 5;
	unsigned int *S = malloc(sizeof(unsigned int));
	*S = 6;

	PETest(hp,a,d,SpA,SpD,S,t1,t2,overFlowName,move1,move2,move3,move4, moveCat);
	*moveCat = SPECIAL;
	PETest(hp,a,d,SpA,SpD,S,t1,t2,emptyName,move1,move2,move3,move4, moveCat);
	*moveCat = STATUS;
	PETest(hp,a,d,SpA,SpD,S,t1,t2,oneName,move1,move2,move3,move4, moveCat);
	return 0;
}



