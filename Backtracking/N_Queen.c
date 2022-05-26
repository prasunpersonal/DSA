#include<stdio.h>

int isSafe(int n, char arr[n][n], int row, int col) {
    for(int i=0; i<col; i++) {
        if(arr[row][i] == 'Q') {
            return 0;
        }
    }
    for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if(arr[i][j] == 'Q') {
            return 0;
        }
    }
    for(int i=row, j=col; i<n && j>=0; i++, j--) {
        if(arr[i][j] == 'Q') {
            return 0;
        }
    }

    return 1;
}

int N_queen(int n, char arr[n][n], int col) {
    if (col >= n) {
        return 1;
    }
    for(int i=0; i<n; i++) {
        if(isSafe(n, arr, i, col)) {
            arr[i][col] = 'Q';
            if(N_queen(n, arr, col+1)) {
                return 1;
            }
            arr[i][col] = '-';
        }
    }
    return 0;
}

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    char arr[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = '-';
        }
    }

    if(N_queen(n, arr, 0)) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                printf("%c\t", arr[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Solution doesn't exist");
    }

    return 0;
}