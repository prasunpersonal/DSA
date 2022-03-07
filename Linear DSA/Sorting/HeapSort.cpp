#include<iostream>
using namespace std;

#define ASSENDING 0
#define DESCENDING 1

template<class T> inline static void print(T *arr, int size){
    cout<<"[";
    for(int i=0; i<size; i++) {
        cout<<arr[i];
        if(i!=size-1) cout<<", ";
    }
    cout<<"]"<<endl;
}

template<class T> inline static void Min_Heap(T *arr, int size, int i) {
    int smallest = i, l = 2*i, r = 2*i+1;

    if(l<size && arr[l]<arr[i]) smallest = l;

    if(r<size && arr[r]<arr[smallest]) smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        Min_Heap(arr, size, smallest);
    }
}

template<class T> inline static void Max_Heap(T *arr, int size, int i) {
    int leargest = i, l = 2*i, r = 2*i+1;

    if(l<size && arr[l]>arr[i]) leargest = l;

    if(r<size && arr[r]>arr[leargest]) leargest = r;

    if (leargest != i) {
        swap(arr[i], arr[leargest]);
        Max_Heap(arr, size, leargest);
    }
}

template<class T> inline static void HeapSort(T *arr, int n, int type=ASSENDING){
    for (int i = n/2-1; i >= 0; i--){
        if(type == 0) Max_Heap(arr, n, i); else Min_Heap(arr, n, i);
    }
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        if(type == 0) Max_Heap(arr, i, 0); else Min_Heap(arr, i, 0);
    }
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    HeapSort<int>(arr, size, DESCENDING);
    print<int>(arr, size);
    return 0;
}