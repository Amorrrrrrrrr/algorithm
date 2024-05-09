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
    int getHeight(TreeNode* cur) {                      /* 利用 return -1 来表示不是平衡二叉树 */
        if (cur == NULL) return 0;
        
        int left = getHeight(cur->left);
        if (left == -1) return -1;
        int right = getHeight(cur->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) {
            return -1;
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (getHeight(root) == -1) {
            return false;
        }
        return true;
    }
};