
#include <stdio.h>

#include "stack_arr.h"


void printStack(Stack312 *stack){
	printf("printing stack: \n");
	printf("top: %d\n",stack->top);
	printf("isEmpty: ");
	printf(isEmpty(*stack)? "true\n":"false\n");
	for(int i=0; i <= stack->top; i ++){
		printf("letter: %c\n", stack->elements[i]);
	}
	printf("\n");
}


int main(){
	Stack312 stack;
	makeStack(&stack);

	printStack(&stack);

	push('c', &stack);
	push('d', &stack);
	push('a', &stack);
	push('k', &stack);
	push('u', &stack);
	push('s', &stack);

	
	printStack(&stack);

	printf("popping: %c\n", pop(&stack));

	printStack(&stack);

	printf("popping: %c\n", pop(&stack));
	
	printStack(&stack);

	printf("popping: %c\n", pop(&stack));
	
	printStack(&stack);


	return 0;
}

