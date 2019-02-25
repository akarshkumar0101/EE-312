//
//  stack_arr.c
//  
//
//  Created by Akarsh Kumar on 2/20/19.
//

#include <stdio.h>
#include <stdlib.h>

#include "stack_arr.h"

void makeStack(Stack312 *s){
    (*s).top = -1;
}

bool isFull(Stack312 s){
    return s.top == MAX_ELEMENTS-1;
}

bool isEmpty(Stack312 s){
    return s.top == -1;
}

void push(StackEntry e,Stack312 *s){
    s->elements[++ s->top] = e;
}

StackEntry pop(Stack312 *s){
    return s->elements[s->top --];
}

