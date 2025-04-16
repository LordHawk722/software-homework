#include <iostream>
#include <vector>
using namespace std;
void warshall(vector<vector<int>>& graph) {
    int n = graph.size(); 

    // 动态规划，更新传递闭包矩阵
    for (int k = 0; k < n; k++) {      
        for (int i = 0; i < n; i++) {    
            for (int j = 0; j < n; j++) {
                
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    int n; 
    cout << "请输入图的顶点数: ";
    cin >> n;


    vector<vector<int>> graph(n, vector<int>(n));
    cout << "请输入邻接矩阵(用0和1表示): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }


    warshall(graph);

 
    cout << "传递闭包矩阵为: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
