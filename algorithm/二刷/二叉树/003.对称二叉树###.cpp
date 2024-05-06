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

/* 两棵树同时遍历 */
class Solution {
public:
    bool travel(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL && right != NULL || left != NULL && right == NULL) return false;
        if (left->val != right->val) return false;

        bool outside = travel(left->left, right->right);
        bool inside = travel(left->right, right->left);
        return outside && inside;

    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return travel(root->left, root->right);
    }
};