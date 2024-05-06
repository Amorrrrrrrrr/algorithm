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
    int maxSum = INT_MIN;
    int travel(TreeNode* cur) {
        if (cur == NULL) return 0;

        int left = max(travel(cur->left), 0);               /* 子树的最大路径和小于0，不选择子树 */
        int right = max(travel(cur->right), 0);

        maxSum = max(left + right + cur->val, maxSum);      /* 更新最大路径和 */

        return cur->val + max(left, right);                 /* 向上一层传递 */
    }

    int maxPathSum(TreeNode* root) {
        travel(root);
        return maxSum;
    }
};