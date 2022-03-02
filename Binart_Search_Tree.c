#include<stdio.h>
#include<stdlib.h>

typedef struct stud{
    int data;
    struct stud *left, *right;
}BST;

BST* insert(BST* root, int data){
    if(root == NULL){
        BST* bst = (BST*)malloc(sizeof(BST));
        bst->data = data;
        bst->left = NULL;
        bst->right = NULL;
        return bst;
    }else if(root->data > data){
        root->left = insert(root->left, data);
    }else if(root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}

BST* delete(BST* root, int data){
    if(root != NULL){
        if(data < root->data){
            root->left = delete(root->left, data);
        }else if(data > root->data){
            root->right = delete(root->right, data);
        }else{
            if(root->left == NULL){
                root = root->right;
            }else if(root->right == NULL){
                root = root->left;
            }else{
                BST* tmp = root->right;
                while(tmp->left != NULL){
                    tmp = tmp->left;
                }
                root->data = tmp->data;
                root->right = delete(root->right, tmp->data);
            }
        }
    }
    return root;
}

int search(BST* root, int data){
    while(root != NULL && root->data != data){
        if(data < root->data){
            root = root->left;
        }else if(data > root->data){
            root = root->right;
        }
    }
    return (root != NULL);
}

void preorder(BST* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BST* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(BST* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    int choice;
    BST* bst = NULL;
    do{
        printf("\nPress 1 for insert, 2 for delete, 3 to search, 4 to Display, 5 to exit: ");
        scanf("%d",&choice);
        int data;
        switch (choice){
            case 1:
                printf("Enter your data to insert: ");
                scanf("%d",&data);
                if(search(bst, data)){
                    printf("Can't add an element which already exists.\n", data);
                }else{
                    bst = insert(bst, data);
                }
                break;
            case 2:
                if(bst == NULL){
                    printf("Tree is Empty! Can't delete.\n");
                }else{
                    printf("Enter your data to delete: ");
                    scanf("%d",&data);
                    bst = delete(bst, data);
                }
                break;
            case 3:
                if(bst == NULL){
                    printf("Cant't search elements in a empty tree.\n");
                }else{
                    printf("Enter your data to search: ");
                    scanf("%d",&data);
                    if(search(bst, data)){
                        printf("%d is present in this tree.\n", data);
                    }else{
                        printf("%d is not present in this tree.\n", data);
                    }
                }
                break;
            case 4:
                printf("Pre Order: ");
                preorder(bst);
                printf("\n");
                printf("In Order: ");
                inorder(bst);
                printf("\n");
                printf("Post Order: ");
                postorder(bst);
                printf("\n");
                break;
            default:
                printf("Wrong Choice\n");
                break;
        }
    }while(choice != 5);
    return 0;
}