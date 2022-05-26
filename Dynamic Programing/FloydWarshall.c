#include<stdio.h>

#define MIN(a,b) (( a<b) ? a : b)

int main(){
    int n;
    printf("Enter no of vertex: ");
    scanf("%d", &n);

    int graph[n][n];
    for(int i=0; i<n; i++) graph[i][i] = 0;

    printf("\nEnter value of edge between 2 vertices (Put '99999' if there is no edge):\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j) {
                printf("Enter value of edge V[%d] -> V[%d]: ", i, j);
                scanf("%d", &graph[i][j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i!=j && i!=k && j!=k) 
                graph[j][k] = MIN(graph[j][k], graph[j][i]+graph[i][k]);
            }
        }
    }

    printf("The matrix is: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%5d\t", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}