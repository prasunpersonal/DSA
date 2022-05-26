#include<iostream>
#include<algorithm>
using namespace std;

template<class T> inline static int LinearSearch(T *arr, int size, T x){
    for (int i=0; i<size; i++) {
        if(arr[i] == x){return i;}
    }
    return -1;
}

int main(){
    int arr[] = {5, 6, 7, 8, 9};
    cout<<LinearSearch<int>(arr, 5, 8)<<endl;

    char arr2[] = {'A', 'B', 'C', 'D', 'E'};
    cout<<LinearSearch<char>(arr2, 5, '2')<<endl;
    return 0;
}