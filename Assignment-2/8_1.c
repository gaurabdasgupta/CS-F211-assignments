#include <stdio.h>
#include <limits.h>

void bfs(int n, int arr[n][n], int dest[n], int v) {
    int queue[n], visited[n], head = 0, tail = 0;
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
        dest[i] = INT_MAX;
    }

    visited[v] = 1;
    dest[v] = 0;
    queue[head] = v;

    while (head <= tail) {
        int u = queue[head++];
        for (int i = 0; i < n; ++i) {
            if (arr[u][i] && !visited[i]) {
                visited[i] = 1;
                dest[i] = dest[u] + 1;
                queue[++tail] = i;
            }
        }
    }
}

int main()
{
    int n, m, t, count = 0;
    scanf("%d%d", &n, &m);
    int arr[n][n], dest[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        arr[u][v] = arr[v][u] = 1;
    }
    scanf("%d", &t);

    for (int i = 0; i < n; ++i) {
        bfs(n, arr, dest, i);
        for (int j = 0; j < n; ++j) {
            if (dest[j] == t)
                count++;
        }
    }

    printf("%d", count / 2);
}