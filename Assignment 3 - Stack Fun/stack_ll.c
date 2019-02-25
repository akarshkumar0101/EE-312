//
//  stack_arr.c
//  
//
//  Created by Akarsh Kumar on 2/20/19.
//

#include <stdio.h>
#include <stdlib.h>

#include "stack_ll.h"



void makeStack(Stack312 *s){
	s->top = NULL;
}

bool isFull(Stack312 s){
	return false;
}

bool isEmpty(Stack312 s){
	return s.top == NULL;
}

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

StackEntry pop(Stack312 *s){
	StackNode *prevHead = s->top;
	s->top = s->top->next;
	//free(prevHead);
	return (*prevHead).pixel;
}
