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

/* 前序遍历 */
class Solution {
public:
    int result;
    void travel(TreeNode* cur) {
        if (cur == NULL) return;                                                        /* 遇到空节点就终止 */

        travel(cur->left);
        travel(cur->right);

        if (cur->left != NULL && cur->left->left == NULL && cur->left->right == NULL) { /* 遇到左叶子的父节点就收集结果 */
            result += cur->left->val;
            return;
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        result = 0;
        travel(root);
        return result;
    }
};