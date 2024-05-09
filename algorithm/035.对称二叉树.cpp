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

  /* 本质：翻转二叉树仍然相同 */
  /* 方法：比较外侧节点，比较内侧节点 */
  /* 后序遍历：底层的处理信息返回给上一层 */
class Solution {
public:
    bool travel(TreeNode* left, TreeNode* right) {             
        if (left == NULL && right == NULL) {
            return true;
        } else if (left == NULL && right != NULL) {
            return false;
        } else if (left != NULL && right == NULL) {
            return false;
        } else if (left->val != right->val) {
            return false;
        }

        bool outside = travel(left->left, right->right);
        bool inside = travel(left->right, right->left);
        return outside&&inside;
    }
    bool isSymmetric(TreeNode* root) {
        return travel(root->left, root->right);
    }
};