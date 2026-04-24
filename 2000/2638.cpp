/**********************
** coded by rladbeka **
**********************/

#include <stdio.h>

#define MAX 105

int arr[MAX][MAX];
int xx[4] = {0, 0, -1, 1};
int yy[4] = {1, -1, 0, 0};
int n, m;
int ans;

// Simple queue implementation in C
typedef struct {
    int x, y;
} Pair;

Pair queue[MAX * MAX];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Pair dequeue() {
    Pair p = queue[front];
    front++;
    return p;
}

int is_empty() {
    return front == rear;
}

void dfs(int x, int y) {
    if (arr[x][y] == 0)
        arr[x][y] = -1;
    else
        return;

    for (int i = 0; i < 4; i++) {
        int X = x + xx[i];
        int Y = y + yy[i];

        if (X >= 1 && X <= n && Y >= 1 && Y <= m)
            dfs(X, Y);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    dfs(1, 1);
    while (1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 1) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int X = i + xx[k];
                        int Y = j + yy[k];

                        if (arr[X][Y] == -1)
                            cnt++;
                    }

                    if (cnt >= 2)
                        enqueue(i, j);
                }
            }
        }

        if (is_empty())
            break;

        while (!is_empty()) {
            Pair p = dequeue();
            int x = p.x;
            int y = p.y;

            arr[x][y] = -1;

            for (int i = 0; i < 4; i++) {
                int X = x + xx[i];
                int Y = y + yy[i];

                if (arr[X][Y] == 0)
                    dfs(X, Y);
            }
        }

        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
