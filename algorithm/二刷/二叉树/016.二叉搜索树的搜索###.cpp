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

 /* 迭代方式 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->val > val) cur= cur->left;
            else if (cur->val < val) cur = cur->right;
            else return cur;
        }
        return NULL;
    }
};

/* 递归方式### */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;

        if (root->val == val) return root;                              /* 根据中的比较结果递归遍历左右子树 */
        if (root->val < val) return searchBST(root->right, val);
        if (root->val > val) return searchBST(root->left, val);

        return NULL;
    }
};