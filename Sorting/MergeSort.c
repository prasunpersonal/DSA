#include<stdio.h>

void Merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];

    for(int i=0; i<n1; i++) L[i] = arr[l+i];
    for(int i=0; i<n2; i++) R[i] = arr[m+i+1];

    for(int i=l, a=0, b=0; a<n1 || b<n2; i++) {
        if(a<n1 && b<n2) {
            if(L[a] > R[b]) arr[i] = R[b++];
            else arr[i] = L[a++];
        } else {
            if(a<n1) arr[i] = L[a++];
            else arr[i] = R[b++];
        }
    }
}

void MergeSort(int arr[], int l, int r) {
    if(l<r){
        int m = (l+r)/2;
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);
        Merge(arr, l, m, r);
    }
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr, 0, size-1);
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}