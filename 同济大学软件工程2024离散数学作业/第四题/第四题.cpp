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
        p[i] = start;        // ��ʼ���ж���ĸ��ڵ�Ϊ���
        key[i] = tb[start][i]; // ��㵽���������Ȩֵ
    }
    key[start] = 0; // ��������Ȩֵ��Ϊ0�����Ϊ�Ѽ���MST

    for (i = 1; i < n; i++) { // ѭ��n-1�Σ�ѡ��n-1����
        int min = INT_MAX;
        int v = -1;

        // �ҵ�δ����MST��Ȩֵ��С�Ķ���
        for (j = 1; j <= n; j++) {
            if (key[j] > 0 && key[j] < min) {
                v = j;
                min = key[j];
            }
        }

        if (v == -1) break; // ����Ҳ�����Ч�Ķ��㣬����ѭ��

        cout << "��С�ķ��ǣ�" << p[v] << "��" << v << endl;

        key[v] = 0; // ��Ƕ���v�Ѽ���MST

        // �����������㵽MST��Ȩֵ
        for (j = 1; j <= n; j++) {
            if (tb[v][j] < key[j]) {
                p[j] = v;       // ���¸��ڵ�Ϊv
                key[j] = tb[v][j]; // ����Ȩֵ
            }
        }
    }
}

int main() {
    int n, m;
    int i, j;
    int u, v, w;

    cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������0����):";
    while (cin >> n >> m) {
        if (m != 0 && n != 0) {
            // ��ʼ���ڽӾ���
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    tb[i][j] = INT_MAX; // ��ʼȨֵΪ�����
                }
            }

            cout << "�����������ߵĽڵ�����Լ����ǵ�Ȩֵ(�Կո�ָ�������):" << endl;
            for (i = 0; i < m; i++) {
                cin >> u >> v >> w;
                tb[u][v] = tb[v][u] = w; // ����ͼ���߶Գ�
            }

            prim(1, n); // �Ӷ���1��ʼPrim�㷨
            cout << endl;
            cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������0����):" << endl;
        }
        else if (n == 0 && m == 0) {
            return 0; // ����0 0 ��������
        }
    }
    return 0;
}
