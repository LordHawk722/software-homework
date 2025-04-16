#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define N 100
int p[N], key[N], tb[N][N];

void prim(int start, int n) {
    int i, j;
    int minCost;
    for (i = 1; i <= n; i++) {
        p[i] = start;        // 初始所有顶点的父节点为起点
        key[i] = tb[start][i]; // 起点到其他顶点的权值
    }
    key[start] = 0; // 起点自身的权值设为0，标记为已加入MST

    for (i = 1; i < n; i++) { // 循环n-1次，选出n-1条边
        int min = INT_MAX;
        int v = -1;

        // 找到未加入MST且权值最小的顶点
        for (j = 1; j <= n; j++) {
            if (key[j] > 0 && key[j] < min) {
                v = j;
                min = key[j];
            }
        }

        if (v == -1) break; // 如果找不到有效的顶点，结束循环

        cout << "最小耗费是：" << p[v] << "和" << v << endl;

        key[v] = 0; // 标记顶点v已加入MST

        // 更新其他顶点到MST的权值
        for (j = 1; j <= n; j++) {
            if (tb[v][j] < key[j]) {
                p[j] = v;       // 更新父节点为v
                key[j] = tb[v][j]; // 更新权值
            }
        }
    }
}

int main() {
    int n, m;
    int i, j;
    int u, v, w;

    cout << "请输入所求图的顶点数目和边的数目(以空格分隔，输入两个0结束):";
    while (cin >> n >> m) {
        if (m != 0 && n != 0) {
            // 初始化邻接矩阵
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    tb[i][j] = INT_MAX; // 初始权值为无穷大
                }
            }

            cout << "请输入两条边的节点序号以及它们的权值(以空格分隔各个数):" << endl;
            for (i = 0; i < m; i++) {
                cin >> u >> v >> w;
                tb[u][v] = tb[v][u] = w; // 无向图，边对称
            }

            prim(1, n); // 从顶点1开始Prim算法
            cout << endl;
            cout << "请输入所求图的顶点数目和边的数目(以空格分隔，输入两个0结束):" << endl;
        }
        else if (n == 0 && m == 0) {
            return 0; // 输入0 0 结束程序
        }
    }
    return 0;
}
