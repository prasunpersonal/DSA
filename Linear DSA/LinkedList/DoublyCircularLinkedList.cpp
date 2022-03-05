#include<iostream>
using namespace std;

template<class T> class Node {
    public:
        T data;
        Node<T> *prev, *next;
    
        Node(T data, Node<T>* prev = NULL, Node<T>* next = NULL){
            this->data = data;
            this->prev = prev;
            this->next = next;
        }
};

template<class T> class DoublyLinkedList {
    private:
        Node<T>* head;
    public:
        DoublyLinkedList(){
            this->head = NULL;
        }
        void insertNode(T data) {
            if(this->head == NULL){
                this->head = new Node<T>(data);
                this->head->prev = this->head->next = this->head;
            } else {
                Node<T>* ptr = this->head;
                while(ptr->next != this->head) ptr = ptr->next;
                this->head->prev = ptr->next = new Node<T>(data, ptr, this->head);
            }
        }
        void insertNodeFront(T data) {
            if(this->head == NULL) {
                this->head = new Node<T>(data);
                this->head->prev = this->head->next = this->head;
            } else {
                Node<T>* newNode = new Node<T>(data, this->head->prev, this->head);
                this->head->prev = this->head->prev->next = newNode;
                this->head = newNode;
            }
        }
        void removeNode(T data){
            if(this->head != NULL){
                if(this->head->data == data) {
                    if(this->head->next == this->head) {
                        this->head = NULL;
                    } else {
                        this->head->prev->next = this->head->next;
                        this->head->next->prev = this->head->prev;
                        this->head = this->head->next;
                    }
                } else {
                    Node<T> *ptr = this->head;
                    do {
                        if(ptr->data == data) {
                            ptr->prev->next = ptr->next;
                            ptr->next->prev = ptr->prev;
                            return;
                        }
                        ptr = ptr->next;
                    } while(ptr != this->head);
                }
            }
        }
        void removeIndex(int index) {
            if(this->head != NULL) {
                if(index == 0) {
                    if(this->head->next == this->head) {
                        this->head = NULL;
                    } else {
                        this->head->prev->next = this->head->next;
                        this->head->next->prev = this->head->prev;
                        this->head = this->head->next;
                    }
                } else {
                    Node<T>* ptr = this->head;
                    for(int i=0; ptr != NULL; i++, ptr = ptr->next) {
                        if(i==index) {
                            ptr->prev->next = ptr->next;
                            if(ptr->next != NULL) ptr->next->prev = ptr->prev;
                        }
                    }
                }
            }
        }
        int indexOf(T data){
            Node<T>* ptr = this->head;
            int i=0;
            do{
                if(ptr->data == data) return i;
                ptr = ptr->next;
                i++;
            } while (ptr != this->head);
            return -1;
        }
        void print(){
            cout<<"[";
            if(this->head != NULL) {
                Node<T>* ptr = this->head;
                do {
                    cout<<ptr->data;
                    ptr = ptr->next;
                    if(ptr != this->head) cout<<", ";
                } while(ptr != this->head);
            }
            cout<<"]"<<endl;
        }
};

int main(){
    DoublyLinkedList<int> *list = new DoublyLinkedList<int>;
    list->insertNode(5);
    list->insertNode(10);
    list->insertNode(15);
    list->insertNode(20);
    list->print();

    list->removeNode(20);
    list->print();

    list->insertNodeFront(25);
    list->insertNodeFront(30);
    list->insertNodeFront(40);
    list->print();

    list->removeIndex(0);
    list->print();

    cout<<list->indexOf(50)<<endl;
    return 0;
}