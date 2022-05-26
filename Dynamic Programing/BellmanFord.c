#include<stdio.h>

#define INF 99999
#define MIN(a,b) (( a<b) ? a : b)


int main(){
    int n;
    printf("Enter no of vertex: ");
    scanf("%d", &n);

    int graph[n][n];
    for(int i=0; i<n; i++) graph[i][i] = INF;

    printf("\nEnter value of edge between 2 vertices (Put '%d' if there is no edge):\n", INF);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j) {
                printf("Enter value of edge V[%d] -> V[%d]: ", i, j);
                scanf("%d", &graph[i][j]);
            }
        }
    }

    int V[n], all_relaxed = 0;
    V[0] = 0;
    for(int i=1; i<n; i++) V[i] = __INT_MAX__;

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(j!=k && graph[j][k] != INF) {
                    V[k] = MIN(V[k], V[j]+graph[j][k]);
                } 
            }
        }
    }

    printf("\nVertex\t - \tDistance from source\n");
    for(int i=0; i<n; i++) {
        printf("%3d\t - \t%3d\n", i, V[i]);
    }
    return 0;
}