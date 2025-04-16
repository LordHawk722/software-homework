#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E;

    // 枚举所有可能的命题变量值 (0 表示假，1 表示真)
    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            for (C = 0; C <= 1; C++) {
                for (D = 0; D <= 1; D++) {
                    for (E = 0; E <= 1; E++) {
                        // 检查给定条件是否成立
                        if ((A || B) &&
                            (!A || C) &&
                            (!D || E) &&
                            (D || !C) &&
                            !E) {
                            // 如果条件成立，则输出 A 和 B
                            cout << "A=" << A << ", B=" << B << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
