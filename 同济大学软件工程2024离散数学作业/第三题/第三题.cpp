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
    cout << "��������������: ";
    cin >> n;
    cout << "��������������: ";
    cin >> d;
    cout << "�������ϵ����:\n";
    for (i = 0; i < n; i++)
    {
        cout << "���������ĵ�" << i + 1 << "��Ԫ��(Ԫ���Կո�ָ�): ";
        for (j = 0; j < d; j++)
            cin >> s[i][j];
    }

    cout << "�����Ӧ���ѡ���㷨\n";
    cout << "1: �Է��հ�\n";
    cout << "2: ���ݱհ�\n";
    cout << "3: �ԳƱհ�\n";
    cout << "4: �˳�\n";
    cin >> z;

    switch (z)
    {
    case 1: zifan(s); break;
    case 2: chuandi(s); break;
    case 3: duichen(s); break;
    case 4: std::exit(0); break;
    default: cout << "��Чѡ��������ѡ��\n"; selectMenu(); break;
    }
}

void output(int s[][MAX])
{
    cout << "�����ϵ����Ϊ:\n";
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
        s2[i][i] = 1;  // �Է��հ�: �����Խ���Ԫ����Ϊ1
    output(s2);
    selectMenu();
}

void duichen(int s2[][MAX])
{
    int s1[MAX][MAX];
    for (i = 0; i < n; i++)
        for (j = 0; j < d; j++)
            s1[j][i] = s2[i][j];  // ��ת�þ���

    for (i = 0; i < n; i++)
        for (j = 0; j < d; j++)
        {
            s2[i][j] = s2[i][j] + s1[i][j];  // �ԳƱհ��������ת�þ���
            if (s2[i][j] > 1)
                s2[i][j] = 1;  // ȷ��Ԫ��Ϊ0��1
        }

    output(s2);
    selectMenu();
}

void chuandi(int s2[][MAX])
{
    int m[MAX][MAX], a[MAX][MAX], k, h;
    int t[MAX][MAX];

    // ��ʼ������
    for (i = 0; i < n; i++)
        for (j = 0; j < d; j++)
        {
            a[i][j] = 0;
            t[i][j] = s2[i][j];
            m[i][j] = s2[i][j];
        }

    // ���ݱհ�
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
