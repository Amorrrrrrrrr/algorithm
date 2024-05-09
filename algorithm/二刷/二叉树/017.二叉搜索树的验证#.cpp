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
    TreeNode* pre = NULL;
    bool isSearch = true;
    void travel(TreeNode* cur) {
        if (cur == NULL) return;

        travel(cur->left);
        if (pre != NULL && cur->val <= pre->val) {
            isSearch = false;
            return;
        }
        pre = cur;
        travel(cur->right);
    }

    bool isValidBST(TreeNode* root) {
        travel(root);
        return isSearch;
    }
};

/* 正确答案，但不好理解 */
class Solution {
public:
    TreeNode* pre = NULL;

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        if (pre != NULL && root->val <= pre->val) {
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);

        return left && right;
    }
};