#include <stdlib.h>
#include <stdio.h>

#include <PokemonEntry/PokemonEntryTestDriver.h>
#include <PokemonEntry/PokemonEntry.h>
#include <PokemonEntry/Typing.h>


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
typedef struct testStruct{

unsigned int HP, A, D, SpA, SpD, S;
Type t1, t2;
char* name;
} testStruct;



void PETest(unsigned int HP, unsigned int A, unsigned int D, unsigned int SpA, unsigned int SpD, unsigned int S, Type t1, Type t2, char* name) {
PokemonEntry *result = NewPokemonEntry();
testStruct a = {HP,A,D,SpA,SpD,S,t1,t2,name};
printf("BEFORENAME\n\n\n\n");
printf("name is %s\n", name);
result->SetName(result, name);
printf("AFTERNAME\n\n\n\n");
result->SetHitPoints(result, &a.HP);
result->SetAttack(result, &a.A);
result->SetDefense(result, &a.D);
result->SetSpecialAttack(result, &a.SpA);
result->SetSpecialDefense(result, &a.SpD);
result->SetSpeed(result, &a.S);
result->SetPrimaryType(result, &a.t1);
result->SetSecondaryType(result, &a.t2);
result->ConsolePrint(result);

DeletePokemonEntry(result);
}




void TestCaseSimulator() {
	char overFlowName[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char emptyName[30] = "";
	char oneName[30] = "a";
	PETest(1,2,3,4,5,6,NONE,DRAGON,overFlowName);
	PETest(1,2,3,4,5,6,NONE,DRAGON,emptyName);
	PETest(1,2,3,4,5,6,NONE,DRAGON,oneName);
	
}



