#include <stdio.h>

#define V 6

void dfs(int grafo[V][V], int v, int visitado[]) {
    // Marca o vértice como visitado
    visitado[v] = 1;

    printf("%d ", v);

    // Percorre os vizinhos
    for (int i = 0; i < V; i++) {
        if (grafo[v][i] == 1 && !visitado[i]) {
            dfs(grafo, i, visitado);
        }
    }
}

int main() {
    int grafo[V][V] = {{0, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 1, 0},
                       {1, 0, 0, 1, 0, 0}, {0, 1, 1, 0, 0, 1},
                       {0, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0}};

    int visitado[V] = {0};

    int origem = 0;

    dfs(grafo, origem, visitado);

    printf("\n");

    return 0;
}