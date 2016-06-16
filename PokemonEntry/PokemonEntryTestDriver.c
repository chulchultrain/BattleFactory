#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <PokemonEntry/PokemonEntryTestDriver.h>
#include <PokemonEntry/PokemonEntry.h>
#include <PokemonEntry/Typing.h>
#include <PokemonEntry/PokemonMove.h>
#include <GlobalDestroyer/GlobalDestroyer.h>

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

void SetGetTest(PokemonEntry *e,Type t1, Type t2);

/*
void PETest(unsigned int HP, unsigned int A, unsigned int D, unsigned int SpA, unsigned int SpD, unsigned int S, Type t1, Type t2, char* name, char *m1, char *m2, char *m3, char *m4, MoveCategory m) {
PokemonEntry *result = NewPokemonEntry();
printf("BEFORENAME\n\n\n\n");
printf("name is %s\n", name);
result->SetName(result, name);
result->SetLevel(result,100);
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
*/


/*
	Helper function for Unit Testing of the Type Feature.
	If the PokemonEntry type returns something different than it was set to then it fails.
*/
void SetGetTest(PokemonEntry *e,Type t1, Type t2) {
	assert(e);
	e->SetPrimaryType(e,t1);
	e->SetSecondaryType(e,t2);
	assert(e->GetPrimaryType(e) == t1);
	assert(e->GetSecondaryType(e) == t2);		
}

/*
	Reach all the typing.
	See if can set both primary and secondary to be same type. 
	Call SetPrimaryType() on all types
	Call SetSeondaryType() on all types and make sure correct state.
	
	Type 1 != Type 2 || Type1 == Type2
	
	(Type1 != NONE & Type2 != NONE) (Type1 ^ Type2 == NONE) || (Type1 & Type2 == NONE)

*/
void UnitTestTypeFeature() {
	PokemonEntry *e = NewPokemonEntry();

	SetGetTest(e,FIRE,FIRE);

	SetGetTest(e,DARK,WATER);

	SetGetTest(e,NONE,PSYCHIC);

	SetGetTest(e,NONE,NONE);

	SetGetTest(e,WATER,NONE);

}


/*
	Make sure each of the stat getters and setters work correctly
	Partition
		Stat > 0, = 0,(Not defined for < 0 since it takes an unsigned int. Requires it to be Nonnegative)
		
		
*/

void UnitTestStatFeature() {
	PokemonEntry *e = NewPokemonEntry();
}


int main() {
/*
	char overFlowName[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char emptyName[30] = "";
	char oneName[30] = "a";

	char move1[30] = "Hyper Beam";
	char move2[30] = "Flex";
	char move3[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char move4[30] = "";

	MoveCategory moveCat = PHYSICAL;
	Type t1 = NONE;
	Type t2 = DRAGON;
	unsigned int hp = 1;
	unsigned int a = 2;
	unsigned int d = 3;
	unsigned int SpA = 4;
	unsigned int SpD = 5;
	unsigned int S = 6;

	PETest(hp,a,d,SpA,SpD,S,t1,t2,overFlowName,move1,move2,move3,move4, moveCat);
	moveCat = SPECIAL;
	PETest(hp,a,d,SpA,SpD,S,t1,t2,emptyName,move1,move2,move3,move4, moveCat);
	moveCat = STATUS;
	PETest(hp,a,d,SpA,SpD,S,t1,t2,oneName,move1,move2,move3,move4, moveCat);
*/
	UnitTestTypeFeature();
	printf("Type Feature Unit Test Passed.\n");
	GlobalDestroyer(1,0,0);
	return 0;
}



