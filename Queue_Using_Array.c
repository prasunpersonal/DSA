#include<stdio.h>
#include<stdlib.h>

typedef struct stud{
    int top, size;
    int* arr;
}Queue;

void push_back(Queue* _queue, int data){
    _queue->arr[++_queue->top] = data;
}
int pop_front(Queue* _queue){
    int elm = _queue->arr[0];
    for(int i=0; i<_queue->top; i++){
        _queue->arr[i] = _queue->arr[i+1];
    }
    _queue->top--;
    return elm;
}
int front(Queue* _queue){
    return _queue->arr[0];
}
int back(Queue* _queue){
    return _queue->arr[_queue->top];
}
int isFull(Queue* _queue){
    return (_queue->top == _queue->size-1);
}
int isEmpty(Queue* _queue){
    return (_queue->top == -1);
}

int main(){
    int n;
    printf("Enter the max size of your queue: ");
    scanf("%d", &n);
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->size = n;
    queue->top = -1;
    queue->arr = (int*)malloc(sizeof(char) * queue->size);
    while(1){
        int choice;
        printf("Enter 1 for push_back or 2 for pop_front or 3 to get front or 4 to get back: ");
        scanf("%d", &choice);
        if(choice == 1){
            if(isFull(queue)){
                printf("Queue is full! Can't push element.\n");
            }else{
                int data;
                printf("Enter your element: ");
                scanf("%d", &data);
                push_back(queue, data);
            }
        }else if(choice == 2){
            if(isEmpty(queue)){
                printf("Queue is empty! Can't pop element.\n");
            }else{
                printf("%d is poped from the queue.\n", pop_front(queue));
            }
        }else if(choice == 3){
            if(isEmpty(queue)){
                printf("Queue is empty!\n");
            }else{
                printf("First element of the queue is: %d\n", front(queue));
            }
        }else if(choice == 4){
            if(isEmpty(queue)){
                printf("Queue is empty!\n");
            }else{
                printf("Last element of the queue is: %d\n", back(queue));
            }
        }else{
            break;
        }
    }
    return 0;
}