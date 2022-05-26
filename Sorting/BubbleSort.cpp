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

template<class T> inline static void BubbleSort(T *arr, int size) {
    for(int i=0; i<size; i++)
        for(int j=0; j<size-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    BubbleSort<int>(arr, size);
    print<int>(arr, size);
    return 0;
}