#include<stdio.h>
#include<stdLIB.h>

typedef struct stud{
    int data;
    struct stud* next;
}Node;

void push_back(Node** _node, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if((*_node) == NULL){
        (*_node) = node;
    }else{
        Node *ptr = (*_node);
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}
int pop_front(Node** _node){
    int elm = (*_node)->data;
    (*_node) = (*_node)->next;
    return elm;
}
int front(Node* _node){
    return _node->data;
}
int back(Node* _node){
    Node *ptr = _node;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}
int isEmpty(Node* _node){
    return (_node == NULL);
}

int main(){
    Node *node = NULL;
    while(1){
        int choice;
        printf("Enter 1 for push_back or 2 for pop_front or 3 to get front or 4 to get back: ");
        scanf("%d", &choice);
        if(choice == 1){
            int data;
            printf("Enter your element: ");
            scanf("%d", &data);
            push_back(&node, data);
        }else if(choice == 2){
            if(isEmpty(node)){
                printf("Queue is empty! Can't pop element.\n");
            }else{
                printf("%d is poped from the queue.\n", pop_front(&node));
            }
        }else if(choice == 3){
            if(isEmpty(node)){
                printf("Queue is empty!\n");
            }else{
                printf("First element of the queue is: %d\n", front(node));
            }
        }else if(choice == 4){
            if(isEmpty(node)){
                printf("Queue is empty!\n");
            }else{
                printf("Last element of the queue is: %d\n", back(node));
            }
        }else{
            break;
        }
    }
    return 0;
}