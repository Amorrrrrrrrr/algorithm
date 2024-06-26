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
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return {};

        queue<TreeNode*> que;
        que.push(root);
        vector<int> result;
        while (!que.empty()) {
            int size = que.size();
            int maxValue = INT_MIN;
            while (size--) {
                TreeNode* cur = que.front(); que.pop();
                if (cur->val > maxValue) maxValue = cur->val;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            result.push_back(maxValue);
        }

        return result;
    }
};