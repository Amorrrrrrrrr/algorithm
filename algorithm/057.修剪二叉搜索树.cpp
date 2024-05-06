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
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) return root;

        if (root->val < low) {                                  /* 在终止条件删除节点时再次递归（因为递归返回的是根节点） */
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        root->left = trimBST(root->left, low, high);            /* 无遍历规则 */
        root->right = trimBST(root->right, low, high);
        return root;
    }
};