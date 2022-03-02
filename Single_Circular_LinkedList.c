#include<stdio.h>
#include<stdlib.h>

typedef struct stud {
    int data;
    struct stud *next;
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
    }
    newNode->next = head;
}

void removeNode(int index){
    Node* ptr = head;
    for(int i=0; i<index-1; i++){
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
}

void printList(){
    if(head != NULL){
        Node* ptr = head;
        do{
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }while(ptr != head);
    }
    printf("NULL\n");
}

int main(){
    insertNode(5);
    insertNode(10);
    insertNode(15);
    printList();
    removeNode(1);
    printList();
    return 0;
}