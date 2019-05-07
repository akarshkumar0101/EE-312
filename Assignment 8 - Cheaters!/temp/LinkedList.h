
#ifndef LinkedList_h
#define LinkedList_h


//stack_ll.h
//Add documentation including Pre and Post conditions for functions

template <class T>
class LinkedList {
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    
public:
    
    LinkedList(){
        head = NULL;
    }
    
    int size(){
        int i=0;
        Node* node = head;
        while(node!=NULL){
            i++;
            node = node->next;
        }
        return i;
    }
    void add(const T& element){
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;
        
        if(head==NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    const T& get(int index){
        int i=0;
        Node* node = head;
        while(i<index){
            node = node->next;
            i++;
        }
        return node->data;
    }
    int getIndex(const T& element){
        int i=0;
        Node* node = head;
        while(node->data != element){
            node = node->next;
            i++;
        }
        return i;
    }
};

#endif
