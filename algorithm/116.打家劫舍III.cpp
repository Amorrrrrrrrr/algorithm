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

 /* 树型DP：二叉树 + 动态规划 */
 /* 后序遍历 + 动态规划 */
class Solution {
public:
    vector<int> travel(TreeNode* cur) {                                 /* 返回值是 dp 数组 
                                                                         * dp[0]: 不偷当前节点所获得的最大金钱为 dp[0]
                                                                         * dp[1]: 偷当前节点所获得的最大金钱为 dp[1]
                                                                         */
        if (cur == NULL) return vector<int>{0, 0};

        vector<int> left = travel(cur->left);
        vector<int> right = travel(cur->right);
        int val0 = max(left[0], left[1]) + max(right[0], right[1]);
        int val1 = cur->val + left[0] + right[0];
        return vector<int>{val0, val1};
    }
    int rob(TreeNode* root) {
        vector<int> ret = travel(root);
        return max(ret[0], ret[1]);
    }
};