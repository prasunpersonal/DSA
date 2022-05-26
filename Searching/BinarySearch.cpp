#include<iostream>
#include<algorithm>
using namespace std;

template<class T> inline static int BinarySearch(T *arr, int size, T x){
    int low=0, high=size-1;
    while(low <= high){
        int m = (high+low)/2;
        if(arr[m] < x){
            low = m+1;
        } else if(arr[m] > x) {
            high = m-1;
        } else {
            return m;
        }
    }
    return -1;
}
        
int main(){
    int arr[] = {5, 6, 7, 8, 9};
    cout<<BinarySearch<int>(arr, 5, 7)<<endl;

    char arr2[] = {'A', 'B', 'C', 'D', 'E'};
    cout<<BinarySearch<char>(arr2, 5, '2')<<endl;
    return 0;
}