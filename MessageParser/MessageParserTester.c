#include <MessageParser/MessageParser.h>
#include <assert.h>
#include <string.h>

/*
	Tokens of every type.
	For NAME tokens, empty name, 1 char name, maximum length char name, overflow name.
	For non-empty name tokens, a letter or a number and a special char. 

	For other tokens, 0,1, other value. and passing a different value into MakeToken for the string value.
*/

void UnitTestToken() {
	Token emptyNameToken = MakeToken(NAME,0,"",0);
	Token oneLetterNameToken = MakeToken(NAME,0,"h",21);
	Token oneNumNameToken = MakeToken(NAME,0,"1",22);
	Token oneSpecialNameToken = MakeToken(NAME,0,"!",23);
	Token regularNameToken = MakeToken(NAME,0,"Charizard",24);
	Token maximumLengthNameToken = MakeToken(NAME,0,"AAAAABBBBBCCCCCDDDDDEEEEEFFFFF",23);
	Token overFlowNameToken = MakeToken(NAME,0,"AAAAABBBBBCCCCCDDDDDEEEEEFFFFFGG",25);
	Token regionToken = MakeToken(REGION,0,"",23);
	Token ivToken = MakeToken(IV,1,"afe",22);
	Token levelToken = MakeToken(LEVEL,12,"2109j",15);

	Token choiceToken = MakeToken(CHOICE,12093,"foi",23);

	PrintToken(emptyNameToken,stdout);
	PrintToken(oneLetterNameToken,stdout);
	PrintToken(oneNumNameToken,stdout);
	PrintToken(oneSpecialNameToken,stdout);
	PrintToken(regularNameToken,stdout);
	PrintToken(maximumLengthNameToken,stdout);
	PrintToken(overFlowNameToken,stdout);
	PrintToken(regionToken,stdout);
	PrintToken(choiceToken,stdout);	
	PrintToken(ivToken,stdout);
	PrintToken(levelToken,stdout);

	printf("Unit Test Token Successful\n");
}

/*
	Testing features of Token Queue
	Pop then Push
	Push then Pop

	IsEmpty, Push, Pop functions

	
*/

void UnitTestTokenQueue() {
	TokenQueue *tq = NewTokenQueue();
	printf("after maketokenqueue\n\n\n");
	Token t = MakeToken(NAME,0,"Charizard",21);
	printf("after maketoken\n\n\n");
	tq->push(tq,t);
	
	tq->push(tq,t);
	t = tq->pop(tq);
	int i = 0;
	for(i = 0; i < 10; i++) {
		tq->push(tq,t);
	}		
	while(!tq->isEmpty(tq) ) {
		t = tq->pop(tq);
		PrintToken(t,stdout);
	}
	printf("Unit Test Token Queue Successful\n");
	DestroyTokenQueue(tq);
}

/*
	Correct input has the order name\nregion\nchoice\niv\nlevel\n
	name = nothing,1 char, multi char, overflow char
	rest = 0,1,multi-digit

*/

void UnitTestParseSimpleMessage() {
	TokenQueue *tq = NewTokenQueue();
	char msg[500] = "Charizard\n1\n22\n333\n4444\n";
	ParseSimpleMessage(tq,msg,500);
	Token t;	
	while(!tq->isEmpty(tq) ) {
		t = tq->pop(tq);
		PrintToken(t,stdout);
	}	
	DestroyTokenQueue(tq);
}

int main() {

	UnitTestToken();
	UnitTestTokenQueue();
	UnitTestParseSimpleMessage();
	return 0;
}
