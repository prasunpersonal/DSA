#include<stdio.h>

int binarySearchIterative(int arr[], int n, int x) {
    int s=0, e=n-1;
    while(s<=e){
        int m = (s+e)/2;
        if(arr[m] < x) s = m+1;
        else if(arr[m] > x) e = m-1;
        else return m;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int s, int e, int x) {
    if(s>e) return -1;
    int m = (s+e)/2;
    if(arr[m] < x) return binarySearchRecursive(arr, m+1, e, x);
    else if(arr[m] > x) return binarySearchRecursive(arr, s, m-1, x);
    else return m;
}

int main(){
    int n, x;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements one by one: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &x);

    printf("%d\n", binarySearchIterative(arr, n, x));
    printf("%d\n", binarySearchRecursive(arr, 0, n-1, x));
    return 0;
}