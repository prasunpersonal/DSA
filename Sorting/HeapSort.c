#include<stdio.h>

void print(int n, int arr[]){
    printf("[");
    for(int i=0; i<n; i++) {
        printf("%d", arr[i]);
        if(i!=n-1) printf(", ");
    }
    printf("]\n");
}

void MIN_HEAP(int n, int arr[], int i) {
    int min = i, l = 2*i, r = 2*i+1;
    if(l<n && arr[l]>arr[i]) min = l;
    if(r<n && arr[r]>arr[min]) min = r;

    if (min != i) {
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
        MIN_HEAP(n, arr, min);
    }
}

void HeapSort(int n, int arr[]){
    for (int i = n/2-1; i >= 0; i--){
        MIN_HEAP(n, arr, i);
    }
    for (int i = n-1; i > 0; i--) {
        int tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        MIN_HEAP(i, arr, 0);
    }
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    HeapSort(size, arr);
    print(size, arr);
    return 0;
}