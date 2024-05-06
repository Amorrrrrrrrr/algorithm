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

/* 后序遍历 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL)) return 0;                           /* 遇到叶子节点，也 return 0（以当前节点为根结点所统计的二叉树的左叶子数之和 */
                                                                                            /* 父节点才开始收集左叶子数之和 */

        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);

        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {  /* 父节点收集左叶子数之和 */
            return root->left->val + right;
        }
        return left + right;
    }
};