#include<stdio.h>

#define MIN(a,b) (( a<b) ? a : b)
#define MAX(a,b) (( a>b) ? a : b)

int FindMax(int arr[], int l, int r) {
    if(l == r) {
        return arr[l];
    } else {
        int mid = (l+r)/2;
        return MAX(FindMax(arr, l, mid), FindMax(arr, mid+1, r));
    }
}

int FindMin(int arr[], int l, int r) {
    if(l == r) {
        return arr[l];
    } else {
        int mid = (l+r)/2;
        return MIN(FindMin(arr, l, mid), FindMin(arr, mid+1, r));
    }
}

int main(){
    int arr[] = {5,6,8,2,5,6,4,3,1,50,55,4,52,25,5,52,2,5,444,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum value of this array is: %d\n", FindMax(arr, 0, n-1));
    printf("Maximum value of this array is: %d\n", FindMin(arr, 0, n-1));
    return 0;
}