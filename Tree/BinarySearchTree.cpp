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
        Node<T>* insert(Node<T>* root, T data){
            if(root == NULL) {
                root = new Node<T>(data);
            } else { 
                if(data < root->data){
                    root->left = insert(root->left, data);
                } else if(data > root->data) {
                    root->right = insert(root->right, data);
                }
            }
            return root;
        }
        Node<T>* remove(Node<T>* root, T data){
            if(root != NULL) {
                if(data < root->data) {
                    root->left = remove(root->left, data);
                } else if(data > root->data){
                    root->right = remove(root->right, data);
                } else {
                    if(root->left == NULL) {
                        root = root->right;
                    } else if(root->right == NULL) {
                        root = root->left;
                    } else {
                        Node<T>* tmp = root->right;
                        while(tmp->left != NULL){
                            tmp = tmp->left;
                        }
                        root->data = tmp->data;
                        root->right = remove(root->right, tmp->data);
                    }
                }
            }
            return root;
        }
        void preorder(Node<T> *root) {
            if(root != NULL) {
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
            }
        }
        void inorder(Node<T> *root) {
            if(root != NULL) {
                inorder(root->left);
                cout<<root->data<<" ";
                inorder(root->right);
            }
        }
        void postorder(Node<T> *root) {
            if(root != NULL) {
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<" ";
            }
        }
    public:
        BST(){root = NULL;}
        void Insert(T data) {
            this->root = insert(this->root, data);
        }
        void Remove(T data) {
            this->root = remove(this->root, data);
        }
        bool Search(T data) {
            Node<T> *ptr = root;
            while(ptr != NULL){
                if(data < ptr->data){
                    ptr = ptr->left;
                } else if(data > ptr->data) {
                    ptr = ptr->right;
                } else {
                    return true;
                }
            }
            return false;
        }
        void PrintPreorder(){
            cout<<"Preorder: ";
            preorder(this->root);
            cout<<endl;
        }
        void PrintInorder(){
            cout<<"Inorder: ";
            inorder(this->root);
            cout<<endl;
        }
        void PrintPostorder(){
            cout<<"Postorder: ";
            postorder(this->root);
            cout<<endl;
        }
};

int main(){
    BST<int> *bst = new BST<int>;

    bst->Insert(5);
    bst->Insert(2);
    bst->Insert(3);
    bst->Insert(1);
    bst->Insert(7);
    bst->Insert(6);
    bst->Insert(9);

    bst->PrintPreorder();
    bst->PrintInorder();
    bst->PrintPostorder();

    bst->Remove(7);

    bst->PrintPreorder();
    bst->PrintInorder();
    bst->PrintPostorder();

    cout<<bst->Search(2)<<endl;
    cout<<bst->Search(20)<<endl;

    return 0;
}