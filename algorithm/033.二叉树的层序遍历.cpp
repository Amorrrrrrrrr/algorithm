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
    vector<vector<int>> levelOrder(TreeNode* root) {            /* 队列 + size */
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {                                   /* 队列为空代表该层没有节点 */
            int size = que.size();                              /* 记录本层的节点数量 */
            vector<int> vec;
            while (size--) {
                TreeNode* cur = que.front();que.pop();
                vec.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};