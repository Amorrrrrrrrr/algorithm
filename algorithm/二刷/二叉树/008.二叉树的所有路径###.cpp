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
    vector<string> res;
    void travel(TreeNode* cur, vector<int>& path) {             /* 回溯时 path 必须传引用，path 传值不用回溯 */
        path.push_back(cur->val);                               /* 因为遍历到叶子节点，所以先处理中的逻辑 */

        if (cur->left == NULL && cur->right == NULL) {          /* 路径遍历到叶子节点 */
            string str;
            str += to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                str += "->";
                str += to_string(path[i]);
            }
            res.push_back(str);
            return;
        }

        if (cur->left) {
            travel(cur->left, path);
            path.pop_back();
        }

        if (cur->right) {
            travel(cur->right, path);
            path.pop_back();
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return {};
        res.clear();
        vector<int> path;
        travel(root, path);
        return res;
    }
};