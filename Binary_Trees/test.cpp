#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

// 定义二叉树的结点结构（链式存储）
struct TreeNode {
    char data;          // 数据域
    TreeNode* left;     // 左孩子指针
    TreeNode* right;    // 右孩子指针
};

// 全局变量，用于记录读取字符串的位置
int inputIndex = 0;
string inputString;

// 1. 二叉树的创建函数 (基于递归的先序创建)
// 读取 inputString，'#' 代表空结点
TreeNode* createTree() {
    char ch;
    // 防止越界
    if (inputIndex >= inputString.length()) {
        return NULL;
    }

    ch = inputString[inputIndex++];

    if (ch == '#') {
        return NULL; // 遇到#返回空指针
    }
    else {
        TreeNode* node = new TreeNode;
        node->data = ch;
        node->left = createTree();  // 递归创建左子树
        node->right = createTree(); // 递归创建右子树
        return node;
    }
}

// 2. 遍历函数
// 先序遍历：根 -> 左 -> 右
void preOrder(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历：左 -> 根 -> 右
void inOrder(TreeNode* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// 后序遍历：左 -> 右 -> 根
void postOrder(TreeNode* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// 3. 查找函数
// 功能：在树中查找 target，如果找到返回所在层数，否则返回 0
// 参数 level 表示当前递归到的层数（初始调用时为 1）
int searchLevel(TreeNode* root, char target, int level) {
    if (root == NULL) {
        return 0; // 路径走到头也没找到
    }

    // 找到了目标，返回当前层数
    if (root->data == target) {
        return level;
    }

    // 先在左子树找
    int leftResult = searchLevel(root->left, target, level + 1);
    if (leftResult != 0) return leftResult; // 左边找到了就直接返回结果

    // 左边没找到，再去右子树找
    return searchLevel(root->right, target, level + 1);
}

int main() {

    inputString = "AB#DF###G##C#E#H##";

    cout << "当前输入的二叉树扩展先序序列为: " << inputString << endl;

    // 重置索引并开始建树
    inputIndex = 0;
    TreeNode* root = createTree();

    cout << "\n--- 遍历结果 ---" << endl;
    cout << "先序遍历: ";
    preOrder(root);
    cout << endl;

    cout << "中序遍历: ";
    inOrder(root);
    cout << endl;

    cout << "后序遍历: ";
    postOrder(root);
    cout << endl;

    cout << "\n--- 查找测试 ---" << endl;

    // 测试案例 1: 查找 'H' (预期结果: 4)
    char target1 = 'H';
    int level1 = searchLevel(root, target1, 1);
    cout << "正在查找字符 '" << target1 << "' ... 所在层数: " << level1 << endl;

    // 测试案例 2: 查找 'S' (预期结果: 0，因为不存在)
    char target2 = 'S';
    int level2 = searchLevel(root, target2, 1);
    cout << "正在查找字符 '" << target2 << "' ... 所在层数: " << level2 << endl;

    return 0;
}