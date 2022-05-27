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

    int V[n], selected[n];
    for(int i=0; i<n; i++) {
        V[i] = INF;
        selected[i] = 0;
    }
    V[0] = 0;

    for(int k=1; k<n; k++) {
        int min = INF, u;
        for(int i=0; i<n; i++) {
            if(!selected[i] && V[i] < min) {
                min = V[i]; u = i;
            }
        }
        selected[u] = 1;
        for(int v=0; v<n; v++) {
            if(u != v && !selected[v] && V[u] != INF && graph[u][v] != INF) {
                V[v] = MIN(V[v], V[u]+graph[u][v]);
            }
        }
    }

    printf("\nVertex\t - \tDistance from source\n");
    for(int i=0; i<n; i++) {
        printf("%3d\t - \t%3d\n", i, V[i]);
    }
    return 0;
}
