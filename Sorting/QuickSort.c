#include<stdio.h>

int Partition(int arr[], int l, int r) {
    int pivot = arr[r];
    for(int j=l; j<=r; j++) {
        if(arr[j] < pivot) {
            int tmp = arr[l];
            arr[l] = arr[j];
            arr[j] = tmp;
            l++;
        }
    }
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
    return l;
}

void QuickSort(int arr[], int l, int r) {
    if(l<r) {
        int p = Partition(arr, l, r);
        QuickSort(arr, l, p-1);
        QuickSort(arr, p+1, r);
    }
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr, 0, size-1);
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}