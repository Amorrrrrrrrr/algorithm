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

 /* 前序遍历/后序遍历，中序遍历不行 */
class Solution {
public:
    void travel(TreeNode* cur) {                
        if (cur == NULL) return;

        swap(cur->left, cur->right);
        travel(cur->left);
        travel(cur->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        travel(root);
        return root;
    }
};