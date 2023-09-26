#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool calculadoraBiparticao(int N, int **G, int src) {
    int colorArr[N];

    for (int i = 0; i < N; ++i)
        colorArr[i] = -1;

    colorArr[src] = 1;

    int fila[N], inicio = -1, fim = -1;
    fila[++fim] = src;

    while (inicio != fim) {
        int u = fila[++inicio];

        if (G[u][u] == 1)
            return false;

        for (int v = 0; v < N; ++v) {
            if (G[u][v] && colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u];
                fila[++fim] = v;
            }
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    return true;
}

int main() {
    int N;
    short int **G;

    // Lendo a matriz
    scanf("%d", &N);
    G = malloc(N * sizeof(short int*));
    for (int i = 0; i < N; i++){
        G[i] = malloc(N * sizeof(short int));
        for (int j = 0; j < N; j++) 
            scanf("%hd", &G[i][j]);
    }

    // Verificando se o grafo é bipartido
    calculadoraBiparticao(N, G, 0) ? printf("Bazinga!\n") : printf("Fail!\n");

    return 0;
}
