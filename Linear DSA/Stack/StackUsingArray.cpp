#include<iostream>
#include<cstdlib>
using namespace std;

template<class T> class Stack {
    private:
        int top, size;
        T *arr;
    public:
        Stack(int size){
            this->size = size;
            this->top = -1;
            this->arr = new T[size];
        }
        void push(T data){
            if(top != this->size){
                top++;
                this->arr[top] = data;
            }
        }
        void pop() {
            top--;
        }
        T peek() {
            return arr[top];
        }
        void print(){
            cout<<"[";
            for(int i=0; i<top; i++){
                cout<<arr[i];
                if(i != top-1) cout<<", ";
            }
            cout<<"]"<<endl;
        }
};


int main(){
    Stack<int> *stack = new Stack<int>(5);
    stack->push(5);
    stack->push(6);
    stack->push(6);
    stack->push(6);
    stack->push(6);

    stack->print();
    stack->pop();
    stack->print();
    return 0;
}