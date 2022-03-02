#include<iostream>
#include<algorithm>
using namespace std;

class Search{
    public:
        template<class T> static int LinearSearch(T *arr, int size, T x){
            for (int i=0; i<size; i++) {
                if(arr[i] == x){return i;}
            }
            return -1;
        }
        template<class T> static int BinarySearch(T *arr, int size, T x){
            int low=0, high=size-1;
            while(low <= high){
                int m = (high+low)/2;
                // int m = low + ((high-low)/2);
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
        template<class T> static int InterpolationSearch(T *arr, int size, T x){
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
};

int main(){
    int arr[] = {5, 6, 7, 8, 9};
    cout<<Search::LinearSearch<int>(arr, 5, 2)<<endl;
    cout<<Search::BinarySearch<int>(arr, 5, 7)<<endl;
    cout<<Search::InterpolationSearch<int>(arr, 5, 2)<<endl;

    char arr2[] = {'A', 'B', 'C', 'D', 'E'};
    cout<<Search::LinearSearch<char>(arr2, 5, '2')<<endl;
    cout<<Search::BinarySearch<char>(arr2, 5, 'D')<<endl;
    cout<<Search::InterpolationSearch<char>(arr2, 5, 'C')<<endl;
    return 0;
}