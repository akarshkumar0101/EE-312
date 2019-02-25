//Equation checker

// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdbool.h>

#include "stack_arr.h"
 
#define MAX_STR_LENGTH 100


char * checkEquation(char *eqstr);
char * concat(const char *s1, const char *s2);
char * charToString(char c);
bool isParenthesisChar(char parenthesisChar);
int indexOfParenthesisChar(char parenthesisChar);

const char * PARENTHESIS = "()[]<>";

int main(int argc, char *argv[]){
	char *fName = argv[1];

	FILE *fp = fopen(fName, "r");

	char buffer[MAX_STR_LENGTH];

	while(1){
		char* ptr = fgets(buffer, MAX_STR_LENGTH, fp);
		if(ptr == NULL){
			break;
		}
		int rawBufferLen = strlen(buffer);
		if(buffer[rawBufferLen-1] == '\n'){
			buffer[rawBufferLen-1] = '\0';
		}


		int rowlen = strlen(buffer);



		//rowlen+1 to include space for null terminating character
		char *eqstr = malloc((rowlen + 1) * sizeof(char));
		strcpy(eqstr, buffer);

		char *validityString = checkEquation(eqstr);
		printf("%s === %s\n", eqstr, validityString);

	}


	
	printf("\n");


	return 0;
}

char * checkEquation(char *eqstr){
	char *answer = "valid expression";

	Stack312 stack;
	makeStack(&stack);

	for(int i=0; i < strlen(eqstr); i ++){
		char characterFound = eqstr[i];

		if(!isParenthesisChar(characterFound)){
			continue;
		}

		int indexOfFound = indexOfParenthesisChar(characterFound);

		if(indexOfFound % 2 == 0){
			push(characterFound, &stack);
		}
		else{
			if(isEmpty(stack)){
				answer = concat("closing without an open ", charToString(PARENTHESIS[indexOfFound-1]));
				return answer;
			}
			char poppedParenthesis = pop(&stack);

			int indexOfPopped = indexOfParenthesisChar(poppedParenthesis);
			if(indexOfPopped + 1 != indexOfFound){
				answer = concat("missing ", charToString(PARENTHESIS[indexOfPopped+1]));
				return answer;
			}
		}
		
	}
	if(!isEmpty(stack)){
		char poppedParenthesis = pop(&stack);
		answer = concat("missing ", charToString(poppedParenthesis));
	}


	return answer;
}

char * concat(const char *s1, const char *s2){
	//+1 for \0
	char *resultString = (char *) malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(resultString, s1);
	strcat(resultString, s2);
	return resultString;
}
char * charToString(char c){
	char * resultString = (char *) malloc(2 * sizeof(char));
	resultString[0] = c;
	resultString[1] = '\0';
	return resultString;
}

bool isParenthesisChar(char parenthesisChar){
	char* ptrToChar = strchr(PARENTHESIS, parenthesisChar);
	return ptrToChar != NULL;
}
int indexOfParenthesisChar(char parenthesisChar){
	char* ptrToChar = strchr(PARENTHESIS, parenthesisChar);
	int index = (ptrToChar-PARENTHESIS) / sizeof(char);
	return index;
}



