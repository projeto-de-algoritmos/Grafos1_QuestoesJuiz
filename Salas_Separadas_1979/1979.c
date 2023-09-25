#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1005
#define oo 0x3f3f3f3f

int g[MAX_N][MAX_N];
int dis[MAX_N];

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        memset(g, 0, sizeof(g));
        memset(dis, oo, sizeof(dis));

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            getchar();

            char q[100000];
            fgets(q, sizeof(q), stdin);

            char *p = strtok(q, " ");
            int v[100];
            int cnt = 0;

            while (p != NULL) {
                v[cnt++] = atoi(p);
                p = strtok(NULL, " ");
            }

            for (int j = 0; j < cnt; j++) {
                g[x][v[j]] = 1;
                g[v[j]][x] = 1;
            }
        }

        int flag = 1;
        for (int i = 1; i <= 2 * n; i++) {
            if (dis[i] == oo) {
                dis[i] = 0;
                int queue[MAX_N];
                int front = 0, rear = 0;
                queue[rear++] = i;

                while (front < rear) {
                    int u = queue[front++];
                    for (int j = 1; j <= 2 * n; j++) {
                        if (g[u][j]) {
                            if (dis[j] == oo) {
                                dis[j] = dis[u] + 1;
                                queue[rear++] = j;
                            } else if (dis[j] == dis[u]) {
                                flag = 0;
                                break;
                            }
                        }
                    }

                    if (!flag) break; // Se a bandeira for falsa, sai do loop
                }
            }

            if (!flag) break; // Se a bandeira for falsa, sai do loop externo
        }

        if (flag)
            printf("SIM\n");
        else
            printf("NAO\n");
    }
    return 0;
}