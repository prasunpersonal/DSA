#include<iostream>
using namespace std;

template<class T> class Queue {
    private:
        T* arr;
        int front, rare, size;
    public:
        Queue(int size){
            this->size = size;
            arr = new T[size];
            this->front = this->rare = 0;
        }
        void enqueue(T data){
            if(rare < size) arr[this->rare++] = data;
        }
        void dequeue(){
            if(this->front !=  this->rare) this->front++;
        }
        void print(){
            cout<<"[";
            for(int i=this->front; i<this->rare; i++) {
                cout<<arr[i];
                if(i != this->rare-1) cout<<", ";
            }
            cout<<"]"<<endl;
        }
};

int main(){
    Queue<int> *queue = new Queue<int>(4);
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