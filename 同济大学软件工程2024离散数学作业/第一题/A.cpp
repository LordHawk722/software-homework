#include <iostream>
using namespace std;

int main()
{
    int i, j;
    char s;

    while (true) {
        // �������
        cout << "***************************************\n";
        cout << "**                                   **\n";
        cout << "**        ��ӭ�����߼��������       **\n";
        cout << "**                                   **\n";
        cout << "***************************************\n\n";

        // ��ȡ P �� Q ��ֵ
        cout << "������P��ֵ��0��1��,�Իس�����: ";
        cin >> i;
        while (i != 0 && i != 1) {
            cout << endl;
            cout << "P��ֵ��������, ����������" << endl;
            cout << "������P��ֵ��0��1��,�Իس�����: ";
            cin >> i;
        }
        cout << endl;
        cout << "������Q��ֵ��0��1��,�Իس�����: ";
        cin >> j;
        while (j != 0 && j != 1) {
            cout << endl;
            cout << "Q��ֵ��������, ����������" << endl;
            cout << "������Q��ֵ��0��1��,�Իس�����: ";
            cin >> j;
        }

        // �����߼�������
        int a[4];
        a[0] = i && j;  // ��ȡ (AND)
        a[1] = i || j;  // ��ȡ (OR)
        a[2] = (!i) || j;  // ���� (�̺�)
        a[3] = ((!i) || j) && ((!j) || i);  // ˫���� (��ֵ)

        // ������
        cout << "\n��ȡ:\n      P/\\Q=" << a[0] << endl;
        cout << "��ȡ:\n      P\\/Q=" << a[1] << endl;
        cout << "����:\n      P->Q=" << a[2] << endl;
        cout << "˫����:\n      P<->Q=" << a[3] << endl;

        // ѯ���Ƿ����
        cout << "\n�Ƿ��������?��y/n��: ";
        cin >> s;
        if (s == 'n') {
            cout << "��ӭ�´��ٴ�ʹ��! Press any key to continue";
            break;  // �˳�����
        }
        else if (s != 'y') {
            continue;
        }
    }

    return 0;
}
