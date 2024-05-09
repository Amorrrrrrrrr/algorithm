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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<double> result;
        while(!que.empty()) {
            int size = que.size();
            int divide = size;
            double sum = 0;
            while (size--) {
                TreeNode* cur = que.front();que.pop();
                sum += cur->val;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            result.push_back(sum / divide);
        }
        return result;
    }
};