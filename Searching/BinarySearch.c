#include<stdio.h>

int binarySearchIterative(int arr[], int n, int x) {
    int s=0, e=n-1;
    while(s<=e){
        int m = (s+e)/2;
        if(arr[m] > x) s = m+1;
        else if(arr[m] < x) e = m-1;
        else return m;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int s, int e, int x) {
    if(s>e) return -1;
    int m = (s+e)/2;
    if(arr[m] > x) return binarySearchRecursive(arr, m+1, e, x);
    else if(arr[m] < x) return binarySearchRecursive(arr, s, m-1, x);
    else return m;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    printf("%d\n", binarySearchIterative(arr, 9, 5));
    printf("%d\n", binarySearchIterative(arr, 9, 50));
    printf("%d\n", binarySearchRecursive(arr, 0, 8, 5));
    printf("%d\n", binarySearchRecursive(arr, 0, 8, 50));
    
    return 0;
}