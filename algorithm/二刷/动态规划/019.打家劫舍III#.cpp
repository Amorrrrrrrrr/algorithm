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
    vector<int> travel(TreeNode* cur) {
        if (cur == NULL) return { 0, 0 };

        vector<int> left = travel(cur->left);
        vector<int> right = travel(cur->right);

        return { max(left[1], left[0]) + max(right[0], right[1]), left[0] + right[0] + cur->val };
    }

    int rob(TreeNode* root) {
        vector<int> ret = travel(root);
        return max(ret[0], ret[1]);
    }
};