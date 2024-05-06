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

/* 二叉搜索树特性：中序遍历的时候元素是单调递增的 */
class Solution {
public:
    long long preValue = LONG_MIN;              /* 记录前一个结点的值 */
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        if (root->val > preValue) {
            preValue = root->val;
        }
        else return false;
        bool right = isValidBST(root->right);
        return left && right;                   /* 左中右考虑了中结点的情况 */
    }
};

/* 双指针优化 */
class Solution {
public:
    TreeNode* pre = NULL;                       /* 记录前一个结点 */
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        if (pre != NULL && pre->val >= root->val) {
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};