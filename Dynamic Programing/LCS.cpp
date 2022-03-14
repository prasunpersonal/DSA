#include<iostream>
#include<cstring>
using namespace std;

string LCS(string A, string B){
    int m = A.length();
    int n = B.length();
    int arr[m+1][n+1];
    string seq;

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0){
                arr[i][j] = 0;
            } else {
                if(A.at(i-1) == B.at(j-1)) arr[i][j] = arr[i-1][j-1] + 1;
                else arr[i][j] = (arr[i][j-1] > arr[i-1][j]) ? arr[i][j-1] : arr[i-1][j];
            }
        }
    }

    int i = m, j = n;
    while(seq.length() < arr[m][n]){
        if(arr[i][j] == arr[i][j-1]) j--;
        else if(arr[i][j] == arr[i-1][j]) i--; 
        else {
            seq.insert(seq.begin(), A.at(i-1));
            i--; j--;
        }
    }
    return seq;
}

int main(){
    cout<<LCS("abcefghxq", "ceopqrah");
    return 0;
}