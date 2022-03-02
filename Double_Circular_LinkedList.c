#include<stdio.h>
#include<stdlib.h>

typedef struct stud {
    int data;
    struct stud *next;
    struct stud *prev;
}Node;

Node *head = NULL;

void insertNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL){
        head = newNode;
    }else{
        Node* ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    head->prev = newNode;
    newNode->next = head;
}

void removeNode(int index){
    Node* ptr = head;
    for(int i=0; i<index-1; i++){
        ptr = ptr->next;
    }
    ptr->next->next->prev = ptr;
    ptr->next = ptr->next->next;
}

void printListForward(){
    if(head != NULL){
        printf("Printing forward: ");
        Node* ptr = head;
        do{
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }while(ptr != head);
    }
    printf("NULL\n");
}

void printListBackward(){
    if(head != NULL){
        printf("Printing backward: ");
        Node* ptr = head->prev;
        do{
            printf("%d->", ptr->data);
            ptr = ptr->prev;
        }while(ptr->next != head);
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