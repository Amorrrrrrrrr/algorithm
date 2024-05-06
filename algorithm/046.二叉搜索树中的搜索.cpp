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

/* 二叉搜索树 */
/* 递归（无遍历顺序） */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;                                  /* 终止条件为找到了/没找到 */
        if (root->val == val) return root;

        TreeNode* ret = NULL;
        if (root->val > val) ret = searchBST(root->left, val);          /* 二叉搜索树的顺序特性确定了遍历顺序 */
        if (root->val < val) ret = searchBST(root->right, val);
        return ret;
    }
};


/* 迭代 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (root->val > val)  root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return NULL;
    }
};