#include<iostream>
#include<stack>
using namespace std;

template<class T> class Node {
    public:
        T data;
        Node<T>* prev;
    
        Node(T data, Node<T>* prev){
            this->data = data;
            this->prev = prev;
        }
};

template<class T> class Stack {
    private:
        Node<T> *top;
    public:
        Stack(){
            this->top = NULL;
        }
        void push(T data){
            this->top = new Node<T>(data, this->top);
        }
        void pop() {
            if(this->top != NULL) this->top = this->top->prev;
        }
        T peek() {
            return this->top->data;
        }
        void print(){
            cout<<"[";
            Node<T>* ptr = this->top;
            while(ptr != NULL) {
                cout<<ptr->data;
                ptr = ptr->prev;
                if(ptr != NULL) cout<<", ";
            }
            cout<<"]"<<endl;
        }
};

int main(){
    Stack<int> *stack = new Stack<int>;
    stack->push(5);
    stack->push(10);
    stack->push(15);
    stack->push(20);
    stack->print();

    stack->pop();
    stack->print();

    cout<<stack->peek();

    return 0;
}