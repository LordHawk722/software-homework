#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// �������ڵ�ṹ��
struct TreeNode {
    int num;               // �ڵ�Ȩֵ
    TreeNode* Lnode;       // ������
    TreeNode* Rnode;       // ������
    TreeNode(int val) : num(val), Lnode(nullptr), Rnode(nullptr) {}
};

// ȫ�ֱ���
vector<TreeNode*> nodes;   // �������нڵ�
string prefixCode;         // ����ǰ׺��

// ��ʼ��Ҷ�ӽڵ�
void initNodes(const vector<int>& frequencies) {
    for (int freq : frequencies) {
        nodes.push_back(new TreeNode(freq));
    }
}

// ����ڵ����飨����
void sortNodes() {
    sort(nodes.begin(), nodes.end(), [](TreeNode* a, TreeNode* b) {
        return a->num < b->num;
        });
}

// ����Huffman��
TreeNode* constructTree() {
    while (nodes.size() > 1) {
        // ȡ��Ȩֵ��С�������ڵ�
        TreeNode* left = nodes[0];
        TreeNode* right = nodes[1];
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());

        // �ϲ����½ڵ�
        TreeNode* parent = new TreeNode(left->num + right->num);
        parent->Lnode = left;
        parent->Rnode = right;

        // �����½ڵ㲢��������
        nodes.push_back(parent);
        sortNodes();
    }
    return nodes[0]; // ���ظ��ڵ�
}

// ǰ��������ǰ׺��
void preorder(TreeNode* node, string code) {
    if (node != nullptr) {
        if (node->Lnode == nullptr && node->Rnode == nullptr) { // Ҷ�ӽڵ�
            cout << node->num << ": " << code << endl;
        }
        preorder(node->Lnode, code + "0");
        preorder(node->Rnode, code + "1");
    }
}

int main() {
    int n;
    cout << "����ڵ����: ";
    cin >> n;

    vector<int> frequencies(n);
    cout << "����ڵ�: ";
    for (int i = 0; i < n; i++) {
        cin >> frequencies[i];
    }

    initNodes(frequencies);    // ��ʼ��Ҷ�ӽڵ�
    sortNodes();               // �Խڵ�������г�ʼ����
    TreeNode* root = constructTree(); // ����Huffman��
    preorder(root, "");        // ǰ����������ǰ׺��
    return 0;
}
