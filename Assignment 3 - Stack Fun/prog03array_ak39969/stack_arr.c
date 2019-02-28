//
//  stack_arr.c
//  
//
//  Created by Akarsh Kumar on 2/20/19.
//

#include <stdio.h>
#include <stdlib.h>

#include "stack_arr.h"

//makes the stack
void makeStack(Stack312 *s){
    (*s).top = -1;
}

//returns true if the stack is full
bool isFull(Stack312 s){
    return s.top == MAX_ELEMENTS-1;
}

//return true if the stack is empty
bool isEmpty(Stack312 s){
    return s.top == -1;
}

//push an element onto the stack (stack should not be full)
void push(StackEntry e,Stack312 *s){
    s->elements[++ s->top] = e;
}

//pop an element from the stack (stack should not be empty)
StackEntry pop(Stack312 *s){
    return s->elements[s->top --];
}

