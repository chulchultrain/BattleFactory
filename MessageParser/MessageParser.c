#include <MessageParser/MessageParser.h>

typedef struct TokenNode TokenNode;

struct TokenNode {
	Token t;
	TokenNode *next;
};

struct TokenQueuePrivate {
	unsigned int size;
	TokenNode *front;
	TokenNode *back;	
};


void ParseMessage(TokenQueue *tq, char *msg, unsigned int len);


TokenQueue *NewTokenQueue();

void DestroyTokenQueue(TokenQueue *tq);

unsigned int TokenQueueIsEmpty(TokenQueue *tq); //
Token TokenQueuePop(TokenQueue *tq); //
void TokenQueuePush(TokenQueue *tq, Token t); //

void SetTokenQueueFunctionPointers(TokenQueue *tq); //
void SetTokenQueueMem(TokenQueue *tq); //

Token MakeToken(TokenType ty,unsigned int v, char *s, unsigned int len) {
	Token t;
	memset(&t,0,sizeof(Token));
	t.type = ty;
	if(ty != NAME) {
		t.numVal = v; 
	}
	else {
		int i = 0;
		for(i = 0; i < MAX_NAME - 1 && i < len && s[i] != 0; i++) {
			t.strVal[i] = s[i];
		}
		
		//strcpy(t.strVal,s);
		t.strVal[MAX_NAME-1] = 0;
	}
	

	return t;
}

void PrintToken(Token t, FILE *fout) {
	if(fout == 0) {
		printf("Not a correct file pointer\n Should check.\n");
		exit(1);
	}
	switch(t.type) {
		case NAME: fprintf(fout,"Name Token: %s\n", t.strVal); break;
		case REGION: fprintf(fout,"Region Token %u\n", t.numVal); break;
		case CHOICE: fprintf(fout,"Choice Token %u\n", t.numVal); break;
		case IV: fprintf(fout,"IV Token %u\n", t.numVal); break;
		case LEVEL: fprintf(fout, "Level Token %u\n", t.numVal); break;
	}
}	

TokenNode *NewTokenNode(Token t);

TokenNode *NewTokenNode(Token t) {
	TokenNode *newToken = malloc(sizeof(TokenNode));
	if(newToken == 0) {	
		printf("New Token Allocation Failed\n");
		exit(1);
	}
	else {
		newToken->t = t;
		newToken->next = 0;
	}	
	return newToken;
}

TokenQueue *NewTokenQueue() {
	TokenQueue *tq = malloc(sizeof(TokenQueue));
	if(tq == 0) {
		//some arbitrary exit error
		printf("TokenQueue Failed to Allocate\n");
		exit(1);
	}
	else {
		SetTokenQueueFunctionPointers(tq);
		SetTokenQueueMem(tq);
	}
	return tq;
}

void DestroyTokenQueue(TokenQueue *tq) {
	TokenNode *front = tq->mem->front;
	TokenNode *delPtr = front;
	while(delPtr) {
		front = delPtr->next;
		free(delPtr);
		delPtr = front;
	}
	free(tq->mem);
	free(tq);
}

void SetTokenQueueFunctionPointers(TokenQueue *tq) {
	tq->pop = TokenQueuePop;
	tq->push = TokenQueuePush;
	tq->isEmpty = TokenQueueIsEmpty;
}

void SetTokenQueueMem(TokenQueue *tq) {
	tq->mem = malloc(sizeof(TokenQueuePrivate));
	TokenQueuePrivate *mem = tq->mem;
	mem->size = 0;
	mem->front = 0;
	mem->back = 0;
}

Token TokenQueuePop(TokenQueue *tq) {
	TokenNode *front = tq->mem->front;
	TokenNode *back = tq->mem->back;
	Token ret;
	if(front == 0) {
		return ret;
	}
	ret = front->t;
	if(front == back) {
		free(front);
		tq->mem->front = tq->mem->back = 0;
		tq->mem->size = 0;
	}
	else {
		TokenNode *delPtr = front;
		tq->mem->front = front->next;
		free(delPtr);
		tq->mem->size--;
	}
	return ret;
}

void TokenQueuePush(TokenQueue *tq, Token t) {
	TokenNode *newNode = NewTokenNode(t);
	if(tq->mem->size == 0) {
		tq->mem->front = tq->mem->back = newNode;
	}
	else {
		tq->mem->back->next = newNode;
		tq->mem->back = newNode;
	}
	tq->mem->size++;
}

unsigned int TokenQueueIsEmpty(TokenQueue *tq) {
	if(tq->mem->size == 0)
		return 1;
	else
		return 0;
}
/*
	while still characters left to be processed
		find the closest start tag.
		try to match with an end tag
		if a valid tag(NAME,REGION,etc)
		parse out value in between start adn end.
		discard these characters and move on.

		if found a start tag but the next tag is also a start tag remove chars.
		
		A queue of tags and non tags. 
		Tag value end tag. create token
		Otherwise discard whatever we were using to build it.
*/

void ParseMessage(TokenQueue *tq, char *msg, unsigned int len) {
	
	/*
		Find tag parse it. move on.

		while not tag start keep trying to find it. 
		
	*/
/*
	int i = 0, proposedStart = 0, proposedEnd = 0;
	while(i < len && msg[i] != 0) {
		
		
	}
*/	
}


/*
	Parses a simple message consisting only of data.
	VERY dependent not modular good only for server.
	Name newline
	Region	
*/
void ParseSimpleMessage(TokenQueue *tq, char *msg, unsigned int len) {
	int i = 0, cE= 0, counter = 0;
	unsigned int val = 0;
	while(counter < 5 && i < len && msg[i] != 0) {
		val = msg[i] - '0';
		cE = i + 1;
		while(msg[cE] != 0 && msg[cE] != '\n') {
			val *= 10;
			val += (msg[cE] - '0');
			cE++;
			
		}
		tq->push(tq,MakeToken(counter,val,(msg + i),cE - i));
		i = cE;
		i++;
		counter++;
	}
	
}







