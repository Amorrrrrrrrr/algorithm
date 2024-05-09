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

/* 根节点的最小高度就是二叉树的最小深度，后序遍历 */
class Solution {
public:
    int getHeight(TreeNode* cur) {
        if (cur == NULL) return 0;

        int left = getHeight(cur->left);
        int right = getHeight(cur->right);
        if (left == 0 || right == 0) {              /* 处理左右子树有一方为空时的逻辑 */
            return max(left, right) + 1;            /* 另一方的最小高度 + 1 */
        }
        return min(left, right) + 1;
    }
    int minDepth(TreeNode* root) {
        return getHeight(root);
    }
};