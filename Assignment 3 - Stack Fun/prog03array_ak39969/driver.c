//Equation checker

// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdbool.h>

#include "stack_arr.h"
 
#define MAX_STR_LENGTH 100


// Checks the given equation string, and returns a string describing the validity/error. The string returned needs to be freed from memory
char * checkEquation(char *eqstr);
// Combines the two given string with a new string in heap. Returned string needs to be freed.
char * concat(const char *s1, const char *s2);
//converts the char to a string on the heap. Returned string needs to be freed
char * charToString(char c);
// determines if the character is a recognized parenthesis based on PARENTHESIS
bool isParenthesisChar(char charIn);
// returns the index of the parenthesisChar in the variable PARENTHESIS
int indexOfParenthesisChar(char parenthesisChar);


//all recognized parenthetical characters
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
		free(validityString);
		free(eqstr);
	}


	
	printf("\n");


	return 0;
}

char * checkEquation(char *eqstr){
	char *answer;

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
				char *openParStr = charToString(PARENTHESIS[indexOfFound-1]);
				answer = concat("closing without an open ", openParStr);
				free(openParStr);
				return answer;
			}
			char poppedParenthesis = pop(&stack);

			int indexOfPopped = indexOfParenthesisChar(poppedParenthesis);
			if(indexOfPopped + 1 != indexOfFound){
				char *missingParStr = charToString(PARENTHESIS[indexOfPopped+1]);
				answer = concat("missing ", missingParStr);
				free(missingParStr);
				return answer;
			}
		}
		
	}
	if(!isEmpty(stack)){
		char poppedParenthesis = pop(&stack);

		int indexOfMissing = indexOfParenthesisChar(poppedParenthesis) + 1;

		char *missingParStr = charToString(PARENTHESIS[indexOfMissing]);
		answer = concat("missing ", missingParStr);
		free(missingParStr);
		return answer;
	}
	else{
		char *validExpAnswer = "valid expression";
 		answer = malloc((strlen(validExpAnswer)+1)*sizeof(char));
		strcpy(answer, validExpAnswer);
		return answer;	
	}
	
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

bool isParenthesisChar(char charIn){
	char* ptrToChar = strchr(PARENTHESIS, charIn);
	return ptrToChar != NULL;
}
int indexOfParenthesisChar(char parenthesisChar){
	char* ptrToChar = strchr(PARENTHESIS, parenthesisChar);
	int index = (ptrToChar-PARENTHESIS) / sizeof(char);
	return index;
}



