#include<stdio.h>
#include<stdlib.h>

typedef struct stud {
    int data;
    struct stud *next;
    struct stud *prev;
}Node;

Node *head = NULL;
Node *tail = NULL;

void insertNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL){
        head = tail = newNode;
        newNode->prev = NULL;
    }else{
        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
        tail = newNode;
    }
    newNode->next = NULL;
}

void removeNode(int index){
    Node* ptr = head;
    if(index == 0){
    	head = head->next;
    	head->prev = NULL;
	}else{
	    for(int i=0; i<index-1; i++){
	        ptr = ptr->next;
	    }
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
	}
}

void printListForward(){
    if(head != NULL){
        printf("Printing forward: ");
        Node* ptr = head;
        while(ptr != NULL){
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("NULL\n");
}

void printListBackward(){
   if(head != NULL){
       printf("Printing backward: ");
       Node* ptr = tail;
       while(ptr != NULL){
           printf("%d->", ptr->data);
           ptr = ptr->prev;
       }
   }
   printf("NULL\n");
}

int main(){
    insertNode(5);
    insertNode(10);
    insertNode(15);
    insertNode(20);
    insertNode(25);
    printListForward();
   printListBackward();
    removeNode(2);
    printListForward();
   printListBackward();
    return 0;
}
