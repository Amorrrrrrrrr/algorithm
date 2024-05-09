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
    int getSize(TreeNode* cur) {
        if (cur == NULL) return 0;                      /* 终止条件有两个：空节点和满二叉树 */
        TreeNode* left = cur->left;                     /* 判断满二叉树逻辑：完全二叉树中当前结点一直向左遍历的结点个数 = 一直向右遍历的结点个数 */
        TreeNode* right = cur->right;
        int leftSize = 1;
        int rightSize = 1;
        while (left) {
            left = left->left;
            leftSize++;
        }
        while (right) {
            right = right->right;
            rightSize++;
        }
        if (leftSize == rightSize) {
            return (2 << (leftSize - 1)) - 1;
        }

        int leftTreeSize = getSize(cur->left);
        int rightTreeSize = getSize(cur->right);
        return leftTreeSize + rightTreeSize + 1;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return getSize(root);
    }
};