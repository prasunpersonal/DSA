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

template<class T> class SinglyCircularLinkedList {
    private:
        Node<T>* head;
    public:
        SinglyCircularLinkedList(){
            this->head = NULL;
        }
        void insertNode(T data) {
            if(this->head == NULL){
                this->head = new Node<T>(data);
                this->head->next = this->head;
            } else {
                Node<T>* ptr = this->head;
                while(ptr->next != this->head) ptr = ptr->next;
                ptr->next = new Node<T>(data, this->head);
            }
        }
        void insertNodeFront(T data){
            if(this->head == NULL){
                this->head = new Node<T>(data);
                this->head->next = this->head;
            } else {
                Node<T>* ptr = this->head;
                while(ptr->next != this->head){
                    ptr = ptr->next;
                }
                Node<T> *newNode = new Node<T>(data, head);
                ptr->next = newNode;
                this->head = newNode;
            }
        }
        void removeNode(T data){
            if(this->head != NULL){
                if(this->head->data == data) {
                    if(this->head->next == this->head) {
                        this->head == NULL;
                    } else {
                        Node<T>* ptr = this->head;
                        while(ptr->next != this->head && ptr->next->data != data) ptr = ptr->next;
                        if(ptr->next != NULL) ptr->next = ptr->next->next;
                    }
                    this->head = this->head->next;
                } else {
                    Node<T>* ptr = this->head;
                    while(ptr->next != NULL && ptr->next->data != data) ptr = ptr->next;
                    if(ptr->next != NULL) ptr->next = ptr->next->next;
                }
            }
        }
        void removeIndex(int index) {
            if(this->head != NULL) {
                if(index == 0) {
                    this->head = this->head->next;
                } else {
                    Node<T>* ptr = this->head;
                    for(int i=0; i<index-1 && ptr->next != NULL; i++) ptr = ptr->next;
                    if(ptr->next != NULL) ptr->next = ptr->next->next;
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
    SinglyCircularLinkedList<int> *list = new SinglyCircularLinkedList<int>;
    list->insertNode(5);
    list->insertNode(10);
    list->insertNode(15);
    list->insertNode(20);
    list->print();

    list->removeNode(5);
    list->print();

    list->insertNodeFront(25);
    list->print();

    list->removeIndex(20);
    list->print();

    cout<<list->indexOf(50)<<endl;
    return 0;
}