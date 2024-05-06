/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* 求二叉树的最大深度 + 判断 */
class Solution {
public:
    int travel(TreeNode* cur) {
        if (cur == NULL) return 0;

        int left = travel(cur->left);
        if (left == -1) return -1;
        int right = travel(cur->right);
        if (right == -1) return -1;

        if (abs(left - right) < 2) return max(left, right) + 1;
        return -1;
    }

    bool isBalanced(TreeNode* root) {
        if (travel(root) == -1) return false;
        return true;
    }
};