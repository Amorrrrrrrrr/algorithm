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
    int sum = 0;
    void travel(TreeNode* cur, int path) {
        path += cur->val;

        if (cur->left == NULL && cur->right == NULL)  {
            sum += path;
            return;
        }
        
        if (cur->left) travel(cur->left, path * 10);
        if (cur->right) travel(cur->right, path * 10);
    }
    int sumNumbers(TreeNode* root) {
        travel(root, 0);
        return sum;
    }
};