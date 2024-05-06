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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};                    /* 注意根节点为 NULL 的情况 */

        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> path;
            while (size--) {
                TreeNode* cur = que.front(); que.pop();
                path.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            result.push_back(path);
        }
        return result;
    }
};