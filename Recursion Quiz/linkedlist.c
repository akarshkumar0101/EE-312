#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

//Write a recursive function which prints the LinkedList recursively
void printList(struct Node* head){
    if(head != NULL){
        printf("%d ",head->data);
        printList(head->next);
    }
    else{
        printf("\n");
    }
}


//Write a recursive function which prints the LinkedList in reverse order recursively
void printReverseList(struct Node* head){
    if(head != NULL){
        printReverseList(head->next);
        printf("%d ",head->data);
    }
}

int main( )
{
    struct Node nodes[10];
    for(int i = 0; i < 9 ; i++){
        nodes[i].data = i;
        nodes[i].next = &nodes[i+1];
    }

    nodes[9].data = 9;
    nodes[9].next = NULL;

    printList(&nodes[0]);
    printReverseList(&nodes[0]);
    return 0;
}
