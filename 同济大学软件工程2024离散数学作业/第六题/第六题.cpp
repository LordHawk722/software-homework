#include <iostream>
#include <vector>
using namespace std;
void warshall(vector<vector<int>>& graph) {
    int n = graph.size(); 

    // ��̬�滮�����´��ݱհ�����
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
    cout << "������ͼ�Ķ�����: ";
    cin >> n;


    vector<vector<int>> graph(n, vector<int>(n));
    cout << "�������ڽӾ���(��0��1��ʾ): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }


    warshall(graph);

 
    cout << "���ݱհ�����Ϊ: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
