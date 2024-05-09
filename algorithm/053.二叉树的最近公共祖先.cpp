/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 后序遍历 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;                                              /* 终止条件：遇到 p/q 或没遇到 */
        if (root == p || root == q) return root;

        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL) {                                        /* 中的处理逻辑 */
            return root;
        } else if (left != NULL && right == NULL) {
            return left;
        } else if (left == NULL && right != NULL) {
            return right;
        } else {
            return NULL;
        }
    }
};