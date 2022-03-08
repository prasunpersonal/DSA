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

template<class T> class Queue {
    private:
        Node<T> *front, *rare;
    public:
        Queue(){
            this->front = this->rare = NULL;
        }
        void enqueue(T data){
            if(this->front == NULL && this->rare == NULL) {
                this->front = this->rare = new Node<T>(data);
            } else {
                this->rare = this->rare->next = new Node<T>(data);
            }
        }
        void dequeue(){
            if(this->front != NULL && this->rare != NULL) {
                if(this->front == this->rare) this->front = this->rare = NULL;
                else this->front = this->front->next;
            }
        }
        void print(){
            cout<<"[";
            Node<T>* ptr = this->front;
            while(ptr != NULL) {
                cout<<ptr->data;
                ptr = ptr->next;
                if(ptr != NULL) cout<<", ";
            }
            cout<<"]"<<endl;
        }
};

int main(){
    Queue<int> *queue = new Queue<int>;
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