#include<iostream>
using namespace std;

template<class T> class Node {
    public:
        T data;
        Node<T>* next;
    
        Node(T data, Node<T>* next = NULL){
            this->data = data;
            this->next = next;
        }
};

template<class T> class CircularQueue {
    private:
        Node<T> *front, *rare;
    public:
        CircularQueue(){
            this->front = this->rare = NULL;
        }
        void enqueue(T data){
            if(this->front == NULL && this->rare == NULL) {
                this->front->next = this->rare->next = this->front = this->rare = new Node<T>(data);
            } else {
                this->rare = this->rare->next = new Node<T>(data, this->front);
            }
        }
        void dequeue(){
            if(this->front != NULL && this->rare != NULL) {
                if(this->front == this->rare) this->front = this->rare = NULL;
                else this->rare->next = this->front = this->front->next;
            }
        }
        void print(){
            cout<<"[";
            if(this->front != NULL){
                Node<T>* ptr = this->front;
                do {
                    cout<<ptr->data;
                    ptr = ptr->next;
                    if(ptr != this->front) cout<<", ";
                } while(ptr != this->front);
            }
            cout<<"]"<<endl;
        }
};

int main(){
    CircularQueue<int> *queue = new CircularQueue<int>;
    queue->enqueue(5);
    queue->enqueue(10);
    queue->enqueue(15);
    queue->enqueue(20);
    queue->print();

    queue->dequeue();
    queue->print();
    queue->dequeue();
    queue->print();
    queue->dequeue();
    queue->print();
    queue->dequeue();
    queue->print();
    return 0;
}