#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 100;
int s[MAX][MAX], z, n, d, i, j;

void output(int s[][MAX]);
void zifan(int s2[][MAX]);
void duichen(int s2[][MAX]);
void chuandi(int s2[][MAX]);
void selectMenu();

int main()
{
    selectMenu();
    return 0;
}

void selectMenu()
{
    cout << "请输入矩阵的行数: ";
    cin >> n;
    cout << "请输入矩阵的列数: ";
    cin >> d;
    cout << "请输入关系矩阵:\n";
    for (i = 0; i < n; i++)
    {
        cout << "请输入矩阵的第" << i + 1 << "行元素(元素以空格分隔): ";
        for (j = 0; j < d; j++)
            cin >> s[i][j];
    }

    cout << "输入对应序号选择算法\n";
    cout << "1: 自反闭包\n";
    cout << "2: 传递闭包\n";
    cout << "3: 对称闭包\n";
    cout << "4: 退出\n";
    cin >> z;

    switch (z)
    {
    case 1: zifan(s); break;
    case 2: chuandi(s); break;
    case 3: duichen(s); break;
    case 4: std::exit(0); break;
    default: cout << "无效选择，请重新选择\n"; selectMenu(); break;
    }
}

void output(int s[][MAX])
{
    cout << "所求关系矩阵为:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < d; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
}

void zifan(int s2[][MAX])
{
    for (i = 0; i < n; i++)
        s2[i][i] = 1;  // 自反闭包: 将主对角线元素置为1
    output(s2);
    selectMenu();
}

void duichen(int s2[][MAX])
{
    int s1[MAX][MAX];
    for (i = 0; i < n; i++)
        for (j = 0; j < d; j++)
            s1[j][i] = s2[i][j];  // 求转置矩阵

    for (i = 0; i < n; i++)
        for (j = 0; j < d; j++)
        {
            s2[i][j] = s2[i][j] + s1[i][j];  // 对称闭包：矩阵加转置矩阵
            if (s2[i][j] > 1)
                s2[i][j] = 1;  // 确保元素为0或1
        }

    output(s2);
    selectMenu();
}

void chuandi(int s2[][MAX])
{
    int m[MAX][MAX], a[MAX][MAX], k, h;
    int t[MAX][MAX];

    // 初始化矩阵
    for (i = 0; i < n; i++)
        for (j = 0; j < d; j++)
        {
            a[i][j] = 0;
            t[i][j] = s2[i][j];
            m[i][j] = s2[i][j];
        }

    // 传递闭包
    for (h = 0; h < n; h++)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < d; j++)
                if (m[i][j] == 1)
                {
                    for (k = 0; k < n; k++)
                        if (s2[j][k] == 1)
                            a[i][k] = 1;
                }

        for (i = 0; i < n; i++)
            for (j = 0; j < d; j++)
            {
                m[i][j] = a[i][j];
                t[i][j] += a[i][j];
                a[i][j] = 0;
                if (t[i][j] > 1)
                    t[i][j] = 1;
            }
    }

    output(t);
    selectMenu();
}
