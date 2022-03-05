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
                if(this->head->next == this->head) {
                    this->head = NULL;
                } else {
                    Node<T> *ptr = this->head;
                    do {
                        if(ptr->next->data == data) {
                            if(ptr->next == this->head) this->head = ptr->next->next;
                            ptr->next = ptr->next->next;
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
                    } else{
                        Node<T> *ptr = this->head;
                        while(ptr->next != this->head) ptr = ptr->next;
                        this->head = ptr->next->next;
                        ptr->next = ptr->next->next;
                    }
                } else {
                    Node<T>* ptr = this->head;
                    int i=0;
                    do{
                        if(i==index-1){
                            ptr->next = ptr->next->next;
                            break;
                        }
                        ptr = ptr->next;
                        i++;
                    } while (ptr != this->head);
                }
            }
        }
        int indexOf(T data){
            Node<T>* ptr = this->head;
            int i=0;
            do {
                if(ptr->data == data) return i;
                ptr = ptr->next; i++;
            } while (ptr != this->head);
            return -1;
        }
        void print(){
            if(this->head == NULL) {
                cout<<"NULL"<<endl;
            } else {
                Node<T>* ptr = this->head;
                do{
                    cout<<ptr->data<<" ";
                    ptr = ptr->next;
                }while(ptr != this->head);
                cout<<endl;
            }
        }
};

int main(){
    SinglyCircularLinkedList<int> *list = new SinglyCircularLinkedList<int>;
    list->insertNode(5);
    list->insertNode(10);
    list->insertNode(15);
    list->insertNode(20);
    list->print();

    list->removeNode(15);
    list->print();

    list->insertNodeFront(25);
    list->print();

    list->removeIndex(3);
    list->print();

    cout<<list->indexOf(25)<<endl;
    return 0;
}