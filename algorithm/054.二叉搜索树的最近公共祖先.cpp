/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        if (root->val < p->val && root->val < q->val) {
            TreeNode* result = lowestCommonAncestor(root->right, p, q);             /* 鲁棒性（自我考虑：一定会返回一个结果，不会返回 NULL） */
            if (result != NULL) return result; 
        }
        if (root->val > p->val && root->val > q->val) {
            TreeNode* result = lowestCommonAncestor(root->left, p, q);
            if (result != NULL) return result; 
        }
        return root;
    }
};