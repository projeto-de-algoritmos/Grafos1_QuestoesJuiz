#include <stdio.h>
#include <string.h>

int row[] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1};

int isValid(int x, int y) {
    return (x>=0 && y>=0 && x<8 && y<8);
}

int knightMoves(char a[3], char b[3]) {
    int visited[8][8];

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            visited[i][j] = 0;
        }
    }

    int startX = a[0] - 'a';
    int startY = a[1] - '1';
    int endX = b[0] - 'a';
    int endY = b[1] - '1';

    visited[startX][startY] = 1;

    int filaX[64], filaY[64], moves[64];
    int inicio = 0, fim = 0;

    filaX[fim] = startX;
    filaY[fim] = startY;
    moves[fim] = 0;
    fim++;

    while (inicio < fim) {
        int x = filaX[inicio];
        int y = filaY[inicio];
        int move = moves[inicio];
        inicio++;

        if (x == endX && y == endY) {
            return move;
        }

        for (int i = 0; i < 8; i++) {
            int newX = x + row[i];
            int newY = y + col[i];

            if (isValid(newX, newY) && !visited[newX][newY]) {
                visited[newX][newY] = 1;
                filaX[fim] = newX;
                filaY[fim] = newY;
                moves[fim] = move + 1;
                fim++;
            }
        }
    }

    return -1; // Não deveria acontecer se os inputs forem válidos
}

int main() {
    char a[3], b[3];

    while (scanf("%s %s", a, b) != EOF) {
        int moves = knightMoves(a, b);
        printf("To get from %s to %s takes %d knight moves.\n", a, b, moves);
    }

    return 0;
}
