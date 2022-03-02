#include<iostream>
using namespace std;

template<class T> class Node{
    public:
        T data;
        Node *left, *right;
    public:
        Node(T data, Node *left = NULL, Node *right = NULL){
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

template<class T> class BST{
    private:
        Node<T> *root;

        Node<T>* add(Node<T>* root, T data){
            if(root == NULL) {
                root = new Node<T>(data);
            } else {
                if(root->data > data){
                    root->left = add(root->left, data);
                } else {
                    root->right = add(root->right, data);
                }
            }
            return root;
        }

        void preorder(Node<T> *root){
            if(root != NULL){
                preorder(root->left);
                cout<<root->data<<"->";
                preorder(root->right);
            }
        }
    public:
        BST(){root = NULL;}

        void insertNode(T data) {
            root = add(this->root, data);
        }

        void printPreorder(){
            preorder(root);
        }
};

int main(){
    BST<int> *bst = new BST<int>;

    bst->insertNode(5);
    bst->insertNode(2);
    bst->insertNode(3);
    bst->insertNode(1);
    bst->insertNode(7);
    bst->insertNode(6);
    bst->insertNode(9);

    bst->printPreorder();

    return 0;
}