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
    void travel(TreeNode* cur, vector<int>& path, vector<string>& result) {     /* 结果容器需要传引用 */
        path.push_back(cur->val);                                               /* 中：因为终止条件是叶子节点 */

        if (cur->left == NULL && cur->right == NULL) {                          /* 终止条件是叶子节点：因为需要回溯 */
            string ret;
            for (int i = 0; i < path.size() - 1; i++) {
                ret += to_string(path[i]);
                ret += "->";
            }
            ret += to_string(path[path.size() - 1]);
            result.push_back(ret);
            return;
        }

        if (cur->left) {
            travel(cur->left, path, result);
            path.pop_back();                                                    /* 回溯 */
        }
        if (cur->right) {
            travel(cur->right, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        travel(root, path, result);
        return result;
    }
};