#include<iostream>
using namespace std;

template<class T> inline static void print(T *arr, int size){
    cout<<"[";
    for(int i=0; i<size; i++) {
        cout<<arr[i];
        if(i!=size-1) cout<<", ";
    }
    cout<<"]";
}

template<class T> static int partition(T *arr, int start, int end) {
    T pivot = arr[end];
    int i = start;
    for(int j=start; j<=end; j++) {
        if(arr[j] < pivot) {
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

template<class T> inline static void QuickSort(T *arr, int start, int end) {
    if(start<end){
        int p = partition<T>(arr, start, end);
        QuickSort<T>(arr, start, p-1);
        QuickSort<T>(arr, p+1, end);
    }
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    QuickSort<int>(arr, 0, size-1);
    print<int>(arr, size);
    return 0;
}