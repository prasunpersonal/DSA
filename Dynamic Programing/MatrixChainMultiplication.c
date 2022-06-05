#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char* parenthesize(int i, int j, int n, int S[n][n]) {
    char *str = (char*)malloc(sizeof(char));
    if(i == j) {
        strcpy(str, (char[]){'A'+i-1, '\0'});
    } else {
        strcpy(str, "(");
        strcat(str, parenthesize(i, S[i][j], n, S));
        strcat(str, " * ");
        strcat(str, parenthesize(S[i][j]+1, j, n, S));
        strcat(str, ")");
    }
    return str;
}

int MatrixChainMultiplication(int p[], int n) {
    int M[n][n], S[n][n];

    for (int i = 0; i < n; i++) {
        M[i][i] = 0;
        S[i][i] = 0;
    }

    for(int d=1; d<n-1; d++) {
        for(int i=1; i<n-d; i++) {
            int j = i+d;
            M[i][j] = __INT_MAX__;
            for(int k=i; k<j; k++) {
                int x = M[i][k] + M[k+1][j] + (p[i-1] * p[j] * p[k]);
                if(x < M[i][j]) {
                    M[i][j] = x;
                    S[i][j] = k;
                }
            }
        }
    }

    printf("The M matrix is: \n");
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(j<i) printf("x\t");
            else printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("The S matrix is: \n");
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(j<i) printf("x\t");
            else printf("%d\t", S[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Minimum number of multiplication is: %d, for %s", M[1][n-1], parenthesize(1, n-1, n, S));
}

int main(){
    int arr[] = {5,4,6,2,7};
    MatrixChainMultiplication(arr, 5);
    return 0;
}