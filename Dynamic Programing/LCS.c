#include<stdio.h>
#include<string.h>

void LCS(char *str1, char *str2) {
    int n1 = strlen(str1), n2 = strlen(str2);
    int table[n1+1][n2+1];
    for(int i=0; i<=n1; i++) {
        for(int j=0; j<=n2; j++) {
            if(i==0 || j==0) {
                table[i][j] = 0;
            } else {
                if(str1[i-1] == str2[j-1]) table[i][j] = table[i-1][j-1]+1;
                else table[i][j] = (table[i][j-1] > table[i-1][j]) ? table[i][j-1] : table[i-1][j];
            }
        }
    }

    printf("\nThe table is:\n");
    for(int i=0; i<=n1; i++) {
        for(int j=0; j<=n2; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }

    int counter = table[n1][n2];
    char lcs[counter];
    int i=n1, j=n2;
    while(counter >= 0){
        if(table[i][j] == table[i][j-1]) j--;
        else if(table[i][j] == table[i-1][j]) i--; 
        else {
            lcs[counter-1] = str1[i-1];
            counter--; i--; j--;
        }
    }

    printf("\nThe longest common subsequence is: %s",lcs);
}

int main(){
    char str1[20], str2[20];
    printf("Enter your first string (Max 20 chars): ");
    gets(str1);
    printf("Enter your second string (Max 20 chars): ");
    gets(str2);

    LCS(str1, str2);
    return 0;
}