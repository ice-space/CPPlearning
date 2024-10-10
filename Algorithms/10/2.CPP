/**
 * @Author: Yuan
 * @Date: 2024-09-29 20:40:07
 * @LastEditors: Yuan
 * @LastEditTime: 2024-09-29 20:45:49
 * @Description: 
 * @版权声明
 */

#include <iostream>
using namespace std;

// 定义树的节点结构
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
    int maxDepth(TreeNode* root) {
        // 如果当前节点为空，返回深度 0
        if (root == nullptr) {
            return 0;
        }
        // 递归计算左子树和右子树的最大深度
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        // 返回最大深度 + 1（当前节点）
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {
    // 示例构造一棵二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "最大深度: " << solution.maxDepth(root) << endl; // 输出: 3

    return 0;
}
