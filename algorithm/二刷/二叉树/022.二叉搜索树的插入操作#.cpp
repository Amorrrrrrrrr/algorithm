/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 递归方式 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        if (root->val > q->val && root->val > p->val) {
            if (TreeNode* cur = lowestCommonAncestor(root->left , p, q)) return cur;    /* 找到了结果，一直向上传递 */
        }
        if (root->val < p->val && root->val < q->val) {
            if (TreeNode* cur = lowestCommonAncestor(root->right , p, q)) return cur; 
        }

        return root;                                                                    /* 前序遍历，但是因为中的处理逻辑比较麻烦，所以写在了最后 */
    }
};

/* 迭代方式 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        TreeNode* cur = root;
        while (cur) {
            if (cur->val > p->val && cur->val > q->val) cur = cur-> left;
            else if (cur->val < p->val && cur->val < q->val) cur = cur-> right;
            else return cur;
        }
        return NULL;
    }
};