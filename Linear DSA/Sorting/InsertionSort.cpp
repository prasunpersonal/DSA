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

template<class T> inline static void InsertionSort(T *arr, int size) {
    for(int i=1; i<size; i++){
        T key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    InsertionSort<int>(arr, size);
    print<int>(arr, size);
    return 0;
}