
#include <stdio.h>

#include "stack_ll.h"


void printStack(Stack312 *stack){
	printf("printing stack: \n");
	//printf("top: %d\n",stack->top);
	//printf("isEmpty: ");
	//printf(isEmpty(*stack)? "true\n":"false\n");
	
	for(StackNode *currentNode = stack->top; currentNode != NULL; currentNode = currentNode->next){
		printf("letter: %c\n", currentNode->pixel.color);
	}
	printf("\n");
}


int main(){
	Stack312 stack;
	makeStack(&stack);

	printStack(&stack);

	Pixel p[6];
	for(int i=0; i <6;i ++){
		p[i].color = 'a' + i;
	}

	push(p[0], &stack);
	push(p[1], &stack);
	push(p[2], &stack);
	push(p[3], &stack);
	push(p[4], &stack);
	push(p[5], &stack);

	
	printStack(&stack);

	printf("popping: %c\n", (pop(&stack).color));

	printStack(&stack);

	printf("popping: %c\n", pop(&stack).color);
	
	printStack(&stack);

	printf("popping: %c\n", pop(&stack).color);
	
	printStack(&stack);


	return 0;
}

