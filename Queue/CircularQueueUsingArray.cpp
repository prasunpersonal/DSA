
#include<iostream>
using namespace std;

template<class T> class Queue {
    private:
        T* arr;
        int front, rare, size;
    public:
        Queue(int size){
            this->size = size;
            this->arr = new T[size];
            this->front = this->rare = -1;
        }
        void enqueue(T data){
            if (!((this->rare+1)%this->size == this->front)) {
                if(this->front == -1) this->front = 0;
                this->rare = (this->rare+1)%this->size;
                this->arr[this->rare] = data;
            }
        }
        void dequeue(){
            if(this->front == this->rare) {
                this->front = this->rare = -1;
            } else {
                this->front = (this->front+1)%this->size;
            }
        }
        void print(){
            cout<<"[";
            if(this->front != -1){
                int len = (this->rare < this->front) ? this->size+this->rare : this->rare;
                for(int i=this->front; i<=len; i++) {
                    cout<<arr[i%this->size];
                    if(i != this->rare) cout<<", ";
                }
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