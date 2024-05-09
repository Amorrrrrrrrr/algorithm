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

/* 高度：后序遍历，从下往上计数，把叶子结点的高度返回给父节点 */
/* 深度：前序遍历，从上往下计数，求深度的过程符合遍历过程 */

/* 根节点的高度就是二叉树的最大深度，后序遍历 */
class Solution {
public:
    int getHeight(TreeNode* cur) {
        if (cur == NULL) return 0;

        int leftHeight = getHeight(cur->left);
        int rightHeight = getHeight(cur->right);
        return 1 + max(leftHeight, rightHeight);
    }
    int maxDepth(TreeNode* root) {
        return getHeight(root);
    }
};