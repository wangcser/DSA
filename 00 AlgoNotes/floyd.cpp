#include <stdio.h>


int main() {
    int m; // edge
    int n; // vertex
    int adj[n+1][n+1]; // adj-matrix
    int inf = 99999; // or use INT_MAX
    int u, v, cost; // u->v, cost

    // 1. 读入图的点数和边数
    scanf("%d %d", &n, &m);

    // 2. 初始化邻接表
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = inf;
        }
    }

    // 3. 读入边权
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &cost);
        adj[u][v] = cost;
    }

    // 4. floyd-warshall
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // 这里的判断需要考虑溢出问题
                if(adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    // 5. print the result
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            print("%10d", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}