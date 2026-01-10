//102.二叉树的层序遍历
//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。（即逐层地，从左到右访问所有节点）。

#include"Algorithm_150.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        int levelSize = 0;
        if (root)
        {
            q.push(root);
            levelSize = 1;
        }
        while (!q.empty())
        {
            vector<int> v;
            while (levelSize--)
            {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            vv.push_back(v);
            levelSize = q.size();
        }
        return vv;
    }
};