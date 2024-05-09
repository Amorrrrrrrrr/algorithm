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
    int minValue = INT_MAX;
    void travel(TreeNode* cur) {
        if (cur == NULL) return;

        travel(cur->left);
        if (pre != NULL) {
            minValue = min(minValue, cur->val - pre->val);
        }
        pre = cur;
        travel(cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        travel(root);
        return minValue;
    }
};