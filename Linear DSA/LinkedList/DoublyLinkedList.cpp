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
            } else {
                Node<T>* ptr = this->head;
                while(ptr->next != NULL) ptr = ptr->next;
                ptr->next = new Node<T>(data, ptr);
            }
        }
        void insertNodeFront(T data){
            head = new Node<T>(data, NULL, head);
        }
        void removeNode(T data){
            if(this->head != NULL){
                if(this->head->data == data) {
                    this->head = this->head->next;
                    if (this->head != NULL) this->head->prev = NULL;
                } else {
                    Node<T>* ptr = this->head;
                    while(ptr != NULL) {
                        if(ptr->data == data) {
                            ptr->prev->next = ptr->next;
                            if(ptr->next != NULL) ptr->next->prev = ptr->prev;
                            break;
                        }
                        ptr = ptr->next;
                    }
                }
            }
        }
        void removeIndex(int index) {
            if(this->head != NULL) {
                if(index == 0) {
                    this->head = this->head->next;
                    if (this->head != NULL) this->head->prev = NULL;
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
            for(int i=0; ptr != NULL; i++){
                if(ptr->data == data) return i;
                ptr = ptr->next;
            }
            return -1;
        }
        void print(){
            Node<T>* ptr = this->head;
            while(ptr != NULL){
                cout<<ptr->data<<"->";
                ptr = ptr->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    DoublyLinkedList<int> *list = new DoublyLinkedList<int>;
    list->insertNode(5);
    list->insertNode(10);
    list->insertNode(15);
    list->insertNode(20);
    list->print();

    list->removeNode(10);
    list->print();

    list->insertNodeFront(25);
    list->print();

    list->removeIndex(2);
    list->print();

    cout<<list->indexOf(5)<<endl;
    return 0;
}