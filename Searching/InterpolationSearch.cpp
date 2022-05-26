#include<iostream>
#include<algorithm>
using namespace std;

template<class T> inline static int InterpolationSearch(T *arr, int size, T x){
    int low=0, high=size-1;
    while(low <= high){
        int m = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
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
    cout<<InterpolationSearch<int>(arr, 5, 9)<<endl;

    char arr2[] = {'A', 'B', 'C', 'D', 'E'};
    cout<<InterpolationSearch<char>(arr2, 5, 'C')<<endl;
    return 0;
}