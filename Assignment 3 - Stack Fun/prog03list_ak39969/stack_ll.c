//
//  stack_arr.c
//  implementing stack_arr.h
//
//  Created by Akarsh Kumar on 2/20/19.
//

#include <stdio.h>
#include <stdlib.h>

#include "stack_ll.h"


//makes the stack
void makeStack(Stack312 *s){
	s->top = NULL;
}

//returns true if the stack is full
bool isFull(Stack312 s){
	return false;
}

//return true if the stack is empty
bool isEmpty(Stack312 s){
	return s.top == NULL;
}

//push an element onto the stack (stack should not be full)
void push(StackEntry e,Stack312 *s){
	StackNode *newNode = (StackNode *) malloc(sizeof(StackNode));
	newNode->pixel = e;
	newNode->next = NULL;

	if(isEmpty(*s)){
		s->top = newNode;
	}
	else{
		newNode->next = s->top;
		s->top = newNode;
	}
}

//pop an element from the stack (stack should not be empty)
StackEntry pop(Stack312 *s){
	StackNode *prevHead = s->top;
	s->top = s->top->next;
	StackEntry entry = prevHead->pixel;
	free(prevHead);
	return entry;
}
