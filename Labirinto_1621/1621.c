#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 510

typedef struct {
    int primeiro;
    int segundo;
} ii;

// Vetor com as direções possíveis (cima, direita, baixo, esquerda)
ii direcoes[] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

char labirinto[MAX][MAX];
int distancias[MAX][MAX];

int x, y;

int main() {
    int n, m, d;
    while (scanf("%d %d", &n, &m), n || m) {
        // Inicializa o labirinto com espaços em branco
        memset(labirinto, ' ', sizeof(labirinto));
        // Inicializa a matriz de distâncias com -1 (representando distâncias infinitas)
        memset(distancias, -1, sizeof(distancias));
        
        // Lê o labirinto de entrada
        for (int i = 1; i <= n; i++)
            scanf("%s", &labirinto[i][1]);
        
        ii entrada;
        // Encontra a posição inicial do personagem
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (labirinto[i][j] == '.') {
                    entrada.primeiro = i;
                    entrada.segundo = j;
                    break;
                }
            }
        }
        
        d = 0;
        ii q[MAX * MAX];
        int frente = 0, tras = 0;
        
        q[tras++] = entrada;
        distancias[entrada.primeiro][entrada.segundo] = 0;
        
        // Executa a busca em largura para encontrar a distância máxima a partir da posição inicial
        while (frente < tras) {
            int i = q[frente].primeiro, j = q[frente].segundo;
            frente++;
            
            for (int h = 0; h < 4; h++) {
                int ni = i + direcoes[h].primeiro, nj = j + direcoes[h].segundo;
                
                if (labirinto[ni][nj] == '.' && distancias[ni][nj] == -1) {
                    distancias[ni][nj] = distancias[i][j] + 1;
                    
                    if (distancias[ni][nj] > d) {
                        x = ni;
                        y = nj;
                        d = distancias[ni][nj];
                    }
                    
                    q[tras].primeiro = ni;
                    q[tras].segundo = nj;
                    tras++;
                }
            }
        }
        
        // Reinicializa a matriz de distâncias com -1
        memset(distancias, -1, sizeof(distancias));
        frente = 0;
        tras = 0;
        
        // Inicia a segunda busca em largura a partir da posição encontrada anteriormente
        q[tras].primeiro = x;
        q[tras].segundo = y;
        tras++;
        
        distancias[x][y] = 0;
        
        // Executa a segunda busca em largura para encontrar a distância máxima
        while (frente < tras) {
            int i = q[frente].primeiro, j = q[frente].segundo;
            frente++;
            
            for (int h = 0; h < 4; h++) {
                int ni = i + direcoes[h].primeiro, nj = j + direcoes[h].segundo;
                
                if (labirinto[ni][nj] == '.' && distancias[ni][nj] == -1) {
                    distancias[ni][nj] = distancias[i][j] + 1;
                    
                    if (distancias[ni][nj] > d) {
                        x = ni;
                        y = nj;
                        d = distancias[ni][nj];
                    }
                    
                    q[tras].primeiro = ni;
                    q[tras].segundo = nj;
                    tras++;
                }
            }
        }
        
        // Imprime a distância máxima encontrada
        printf("%d\n", d);
    }
    return 0;
}
