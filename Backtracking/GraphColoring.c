#include<stdio.h>

int isSafe(int v, int x, int graph[v][v], int colors[], int c) {
    for(int i=0; i<v; i++) {
        if(graph[x][i] && c == colors[i]) return 0;
    }
    return 1;
}

int colorGraph(int v, int graph[v][v], int m, int colors[m], int x) {
    if (x == v) return 1;
    for(int c=1; c<=m; c++) {
        if(isSafe(v, x, graph, colors, c)) {
            colors[x] = c;
            if(colorGraph(v, graph, m, colors, x+1)) return 1;
            colors[x] = 0;
        }
    }
    return 0;
}

int main(){
    int v, c;
    printf("Enter no of vertex: ");
    scanf("%d", &v);

    int graph[v][v];

    printf("\nIf there is an edge between V[i] -> V[j] put 1 else put 0:\n");
    for(int i=0; i<v; i++){
        graph[i][i] = 0;
        for(int j=i+1; j<v; j++){
            if(i != j) {
                printf("V[%d] -> V[%d]: ", i, j);
                scanf("%d", &graph[i][j]);
                graph[j][i] = graph[i][j];
            }
        }
    }

    printf("Enter no of color: ");
    scanf("%d", &c);
    int colors[v];
    for(int i=0; i<v; i++) colors[i] = 0;

    if(colorGraph(v, graph, c, colors, 0)) {
        for(int i=0; i<v; i++) {
            printf("%d ", colors[i]);
        }
    }
    return 0;
}