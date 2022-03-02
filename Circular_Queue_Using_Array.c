#include<stdio.h>
#include<stdlib.h>

typedef struct stud{
    int front, rare, size;
    int* arr;
}Queue;

void push_back(Queue* _queue, int data){
    if(_queue->front == -1){
        _queue->front = 0;
    }
    _queue->rare =(_queue->rare+1)%_queue->size;
    _queue->arr[_queue->rare] = data;
}
int pop_front(Queue* _queue){
    int tmp = _queue->arr[_queue->front];
    _queue->front =(_queue->front+1)%_queue->size;
    return tmp;
}
int front(Queue* _queue){
    return _queue->arr[_queue->front];
}
int back(Queue* _queue){
    return _queue->arr[_queue->rare];
}
int isFull(Queue* _queue){
    return ((_queue->rare+1)%_queue->size == _queue->front);
}
int isEmpty(Queue* _queue){
    return (_queue->front == _queue->rare && _queue->front != -1);
}
void display(Queue* _queue){
    if(isEmpty(_queue)){
        printf("Queue is empty!");
    }else{
        int len = (_queue->rare < _queue->front) ? _queue->size+_queue->rare : _queue->rare;
        printf("printing queue elements: ");
        for (int i = _queue->front; i <= len; i++){
            printf("%d ",_queue->arr[i%_queue->size]);
        }
    }
    printf("\n");
}

int main(){
    int n, choice=0, count = 0;
    printf("Enter the max size of your queue: ");
    scanf("%d", &n);
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->size = n;
    queue->front = queue->rare = -1;
    queue->arr = (int*)malloc(sizeof(char) * queue->size);
    while (choice!=4){
        printf("\nPress 1 for Enqueu 2 for Dequeue 3 for Display 4 to exit: ");
        scanf("%d",&choice);
                int data;
        switch (choice)
        {
        case 1:
            if(isFull(queue)){
                printf("Queue is full! can't push.\n");
            }else{
                printf("Enter your data to Enqueu: ");
                scanf("%d",&data);
                push_back(queue, data);
            }
            break;
        case 2:
            if(isEmpty(queue)){
                printf("Queue is Empty! can't pop.\n");
            }else{
                printf("Item Dqueue is %d\n", pop_front(queue));
            }
            break;
        case 3:
            display(queue);
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    }
    return 0;
}