#ifndef __MESSAGE_PARSER_H_INCLUDED__
#define __MESSAGE_PARSER_H_INCLUDED__

#include <SpecialConstants/SpecialConstants.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	The purpose of this module is to provide way to parse pieces out of a message that contains information
	about Pokemon Entry Selection. 
	Given a string, the ParseMessage function will populate a TokenQueue with Tokens of information present in the string.

	These Tokens are select pieces of information that will help the server determine what information to retrieve later on.
	The tokens are set up in such a way that they internally have a type and a value.
	NAME - Name of Entry
	REGION - Region of Entry
	CHOICE - Choice of Entry with respect to the Pokemon Name within the Server's Database.
	IV - Number of IVs the Entry will receive
	Level - Level the Entry will receive
*/

typedef struct Token Token;

typedef enum TokenType {
	NAME, REGION, CHOICE, IV, LEVEL
} TokenType;

struct Token {
	TokenType type;
	unsigned int numVal;
	char strVal[MAX_NAME];
};

/*
	The string pointed to by s must be less than size of strVal inside Token structure which is MAX_NAME length. 
	Otherwise, will lead to out of bounds memory errors
*/
Token MakeToken(TokenType ty,unsigned int v, char *s, unsigned int len);
/*

	Helper Token Functions for testing. Will print the Token's state(the type of the token and the value of the token)
	
*/
void PrintToken(Token t, FILE *fout);

typedef struct TokenQueuePrivate TokenQueuePrivate;

typedef struct TokenQueue TokenQueue;

/*
	A Queue for our defined Tokens. Pop, Push, and isEmpty self-explanatory.
	Pop should not be called if queue is empty, will result in undefined behavior. 
	If no more dynamic memory can be allocated, push will fail, resulting in a system exit. 
	
*/

struct TokenQueue {
	TokenQueuePrivate *mem;
	Token (*pop)(TokenQueue *tq);
	void (*push)(TokenQueue *tq, Token t);
	unsigned int (*isEmpty)(TokenQueue *tq);
};

/*
	Will Parse the message given by the char *msg and the message length - len. 
	Will store the tokens in the TokenQueue pointed to by tq, in order that the tokens appear in the msg.
	
	The message should be a sequence of tags, <tag> value </tag> where tag is one of the strings
	"name", "region", "choice", "iv", "level" and value is the corresponding value. 
	
	All but the name tag should have an unsigned integer value as its value. 
	Name may have any string value. 

*/

void ParseMessage(TokenQueue *tq, char *msg, unsigned int len);

/*
	Will Parse the message given by the char *msg and the message length - len. 
	Will store the tokens in the TokenQueue pointed to by tq, in order that the tokens appear in the msg.

	The message will be <name>\n<region>\n<choice>\n<iv>\n<level>\n	
*/

void ParseSimpleMessage(TokenQueue *tq, char *msg, unsigned int len);

/*
	Returns a pointer to a new dynamically allocated new TokenQueue
*/

TokenQueue *NewTokenQueue();

/*
	Destroys a dynamically allocated TokenQueue
*/

void DestroyTokenQueue(TokenQueue *tq);





#endif
