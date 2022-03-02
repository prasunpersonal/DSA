#include<stdio.h>
#include<stdlib.h>

typedef struct stud {
    int data;
    struct stud *next;
    struct stud *prev;
}Node;

Node *front = NULL;
Node*rare = NULL;

void push(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL){
        newNode->prev = NULL;
        front = rare = newNode;
    }else{
        rare->next = newNode;
        newNode->prev = rare;
        rare = rare->next;
    }
}

void pop(){
    rare = rare->prev;
    rare->next = NULL;
}

int getFront(){
    return front->data;
}

int getRare(){
    return rare->data;
}

void printForward(){
    Node* ptr = front;
    do{
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }while(ptr != NULL);
    printf("NULL\n");
}

void printBackward(){
    Node* ptr = rare;
    do{
        printf("%d->", ptr->data);
        ptr = ptr->prev;
    }while(ptr != NULL);
    printf("NULL\n");
}

int main(){
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);
    printForward();
    printBackward();
    printf("Front: %d, Rare: %d;\n", getFront(), getRare());
    pop();
    printForward();
    printBackward();
    printf("Front: %d, Rare: %d;\n", getFront(), getRare());
    return 0;
}