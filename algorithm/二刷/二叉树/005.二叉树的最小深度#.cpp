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

/* 遇到根节点才是最小深度 */
class Solution {
public:
    int travel(TreeNode* cur) {
        if (cur->left == NULL && cur->right == NULL) return 1;

        int left = INT_MAX, right = INT_MAX;                        /* 初值为最大值 */
        if (cur->left) left = travel(cur->left);
        if (cur->right) right = travel(cur->right);

        return min(left, right) + 1;
    }

    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return travel(root);
    }
};