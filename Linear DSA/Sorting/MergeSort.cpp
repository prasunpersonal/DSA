#include<iostream>
using namespace std;

template<class T> inline static void print(T *arr, int size){
    cout<<"[";
    for(int i=0; i<size; i++) {
        cout<<arr[i];
        if(i!=size-1) cout<<", ";
    }
    cout<<"]"<<endl;
}

template<class T> inline static void Merge(T *arr, int start, int mid, int end) {
    int n1 = mid-start+1, n2 = end-mid;
    T *L = new T[n1];
    T *R = new T[n2];
    for(int i=0; i<n1 || i<n2; i++){
        if(i<n1) L[i] = arr[start+i];
        if(i<n2) R[i] = arr[mid+i+1];
    }
    int a=0, b=0;
    for(int i=start; a<n1 || b<n2; i++){
        if (a<n1 && b<n2) {
            if(L[a] <= R[b]) {
                arr[i] = L[a++];
            } else {
                arr[i] = R[b++];
            }
        } else if(a<n1) {
            arr[i] = L[a++];
        } else if (b<n2) {
            arr[i] = R[b++];
        }
    }
    delete[] L;
    delete[] R;
}

template<class T> static void MergeSort(T *arr, int start, int end) {
    if(start<end){
        int mid = (start+end)/2;
        MergeSort<T>(arr, start, mid);
        MergeSort<T>(arr, mid+1, end);
        Merge<T>(arr, start, mid, end);
    }
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    MergeSort<int>(arr, 0, size-1);
    print<int>(arr, size);
    return 0;
}