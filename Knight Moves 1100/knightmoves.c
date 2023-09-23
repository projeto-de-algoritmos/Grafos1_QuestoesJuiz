#include <stdio.h>
#include <string.h>

int row[] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1};

int isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}

int knightMoves(char a[3], char b[3]) {
    int visited[8][8];
    memset(visited, 0, sizeof(visited));

    int startX = a[0] - 'a';
    int startY = a[1] - '1';
    int endX = b[0] - 'a';
    int endY = b[1] - '1';

    visited[startX][startY] = 1;

    int queueX[64], queueY[64], moves[64];
    int front = 0, rear = 0;

    queueX[rear] = startX;
    queueY[rear] = startY;
    moves[rear] = 0;
    rear++;

    while (front < rear) {
        int x = queueX[front];
        int y = queueY[front];
        int move = moves[front];
        front++;

        if (x == endX && y == endY) {
            return move;
        }

        for (int i = 0; i < 8; i++) {
            int newX = x + row[i];
            int newY = y + col[i];

            if (isValid(newX, newY) && !visited[newX][newY]) {
                visited[newX][newY] = 1;
                queueX[rear] = newX;
                queueY[rear] = newY;
                moves[rear] = move + 1;
                rear++;
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
