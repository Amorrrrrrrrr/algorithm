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
    bool travel(TreeNode* cur, int pathSum, int targetSum) {
        if (cur->left == NULL && cur->right == NULL) {
            if (pathSum == targetSum) return true;
            return false;
        }

        if (cur->left) {
            if (travel(cur->left, pathSum + cur->left->val, targetSum)) return true;
        }

        if (cur->right) {
            if (travel(cur->right, pathSum + cur->right->val, targetSum)) return true;
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return travel(root, root->val, targetSum);
    }
};