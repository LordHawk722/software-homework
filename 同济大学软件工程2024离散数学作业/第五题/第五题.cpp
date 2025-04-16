#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 定义树节点结构体
struct TreeNode {
    int num;               // 节点权值
    TreeNode* Lnode;       // 左子树
    TreeNode* Rnode;       // 右子树
    TreeNode(int val) : num(val), Lnode(nullptr), Rnode(nullptr) {}
};

// 全局变量
vector<TreeNode*> nodes;   // 保存所有节点
string prefixCode;         // 保存前缀码

// 初始化叶子节点
void initNodes(const vector<int>& frequencies) {
    for (int freq : frequencies) {
        nodes.push_back(new TreeNode(freq));
    }
}

// 排序节点数组（升序）
void sortNodes() {
    sort(nodes.begin(), nodes.end(), [](TreeNode* a, TreeNode* b) {
        return a->num < b->num;
        });
}

// 构造Huffman树
TreeNode* constructTree() {
    while (nodes.size() > 1) {
        // 取出权值最小的两个节点
        TreeNode* left = nodes[0];
        TreeNode* right = nodes[1];
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());

        // 合并成新节点
        TreeNode* parent = new TreeNode(left->num + right->num);
        parent->Lnode = left;
        parent->Rnode = right;

        // 插入新节点并重新排序
        nodes.push_back(parent);
        sortNodes();
    }
    return nodes[0]; // 返回根节点
}

// 前序遍历输出前缀码
void preorder(TreeNode* node, string code) {
    if (node != nullptr) {
        if (node->Lnode == nullptr && node->Rnode == nullptr) { // 叶子节点
            cout << node->num << ": " << code << endl;
        }
        preorder(node->Lnode, code + "0");
        preorder(node->Rnode, code + "1");
    }
}

int main() {
    int n;
    cout << "输入节点个数: ";
    cin >> n;

    vector<int> frequencies(n);
    cout << "输入节点: ";
    for (int i = 0; i < n; i++) {
        cin >> frequencies[i];
    }

    initNodes(frequencies);    // 初始化叶子节点
    sortNodes();               // 对节点数组进行初始排序
    TreeNode* root = constructTree(); // 构造Huffman树
    preorder(root, "");        // 前序遍历并输出前缀码
    return 0;
}
