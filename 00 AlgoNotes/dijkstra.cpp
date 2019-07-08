#include<stdio.h>

int main() {
    int m; // edge
    int n; // vertex
    int adj[n+1][n+1]; // adj-matrix
    int inf = 99999; // or use INT_MAX
    int u, v, cost; // u->v, cost

    bool set[n+1]; // 存储每个点的集合信息
    int dist[n+1]; // 存储计算的中间结果

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

    // 4. 初始化 dist 数组，表示 1 号点到其余各点的初始路程
    for(int i = 1; i <= n; i++) {
        dist[i] = adj[1][i];
    }

    // 5. 初始化各个点的集合信息，除 1 号点外全部标记为 0
    for(int i = 1; i <= n; i++) {
        set[i] = 0;
    }
    set[1] = 1;

    // 6. dijkstra
    for(int i = 1; i <= n-1; i++) {
        // 通过 dist[] 数组找到距离起点 1 号点距离最近的点
        // 这里可以使用小顶堆进行优化，复杂度 logN
        int min = inf;
        int u = 1;
        for(int j = 1; j <= n; j++) {
            if(set[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        // 将该点标记为确定点
        set[u] = 1;
        // 松弛该点的邻接边
        // 对于稀疏图（E << V^2）这里可以使用邻接表进行优化
        for(int v = 1; v <= n; v++) {
            if(adj[u][v] < inf) {
                if(dist[v] > dist[u] + adj[u][v])
                    dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // 7. 输出最终结果
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}