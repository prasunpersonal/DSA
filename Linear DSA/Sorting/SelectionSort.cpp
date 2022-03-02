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

template<class T> inline static void SelectionSort(T *arr, int size) {
    for(int i=0; i<size-1; i++){
        int min_elm = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[min_elm]){
                min_elm = j;
            }
        }
        swap(arr[i], arr[min_elm]);
    }
}

int main(){
    int arr[] = {5,7,1,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    SelectionSort<int>(arr, size);
    print<int>(arr, size);
    return 0;
}