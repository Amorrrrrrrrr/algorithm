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

/* 中序遍历（但是右中左：从大到小遍历） */
class Solution {
public:
    TreeNode* pre = NULL;
    void travel(TreeNode* cur) {
        if (cur == NULL) return;

        convertBST(cur->right);
        if (pre != NULL) {
            cur->val += pre->val;
        }
        pre = cur;
        convertBST(cur->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};

class Solution {
public:
    int pre = 0;
    void travel(TreeNode* cur) {
        if (cur == NULL) return;

        convertBST(cur->right);
        cur->val += pre;
        pre = cur->val;
        convertBST(cur->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};