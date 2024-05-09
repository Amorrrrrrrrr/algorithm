/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* 在二叉搜索树插入任何一个结点都可以在叶子节点找到它的位置 */

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);             /* 终止条件(到达空节点时)直接返回新节点 */

        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
            return root;
        }
        
        if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
            return root;
        }
        return root;
    }
};