#include <iostream>
using namespace std;

int main()
{
    int i, j;
    char s;

    while (true) {
        // 输出标语
        cout << "***************************************\n";
        cout << "**                                   **\n";
        cout << "**        欢迎进入逻辑运算程序       **\n";
        cout << "**                                   **\n";
        cout << "***************************************\n\n";

        // 读取 P 和 Q 的值
        cout << "请输入P的值（0或1）,以回车结束: ";
        cin >> i;
        while (i != 0 && i != 1) {
            cout << endl;
            cout << "P的值输入有误, 请重新输入" << endl;
            cout << "请输入P的值（0或1）,以回车结束: ";
            cin >> i;
        }
        cout << endl;
        cout << "请输入Q的值（0或1）,以回车结束: ";
        cin >> j;
        while (j != 0 && j != 1) {
            cout << endl;
            cout << "Q的值输入有误, 请重新输入" << endl;
            cout << "请输入Q的值（0或1）,以回车结束: ";
            cin >> j;
        }

        // 计算逻辑运算结果
        int a[4];
        a[0] = i && j;  // 合取 (AND)
        a[1] = i || j;  // 析取 (OR)
        a[2] = (!i) || j;  // 条件 (蕴含)
        a[3] = ((!i) || j) && ((!j) || i);  // 双条件 (等值)

        // 输出结果
        cout << "\n合取:\n      P/\\Q=" << a[0] << endl;
        cout << "析取:\n      P\\/Q=" << a[1] << endl;
        cout << "条件:\n      P->Q=" << a[2] << endl;
        cout << "双条件:\n      P<->Q=" << a[3] << endl;

        // 询问是否继续
        cout << "\n是否继续运算?（y/n）: ";
        cin >> s;
        if (s == 'n') {
            cout << "欢迎下次再次使用! Press any key to continue";
            break;  // 退出程序
        }
        else if (s != 'y') {
            continue;
        }
    }

    return 0;
}
