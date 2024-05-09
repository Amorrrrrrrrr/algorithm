/* Ì°ÐÄ */
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
    int ret = 0;
    int travel(TreeNode* cur) {
        if (cur == NULL) return 2;

        int left = travel(cur->left);
        int right = travel(cur->right);

        if (left == 2 && right == 2) return 1;
        else if (left == 1 || right == 1) {
            ret++;
            return 0;
        }
        else if (left == 0 || right == 0)
            return 2;

        return -1;
    }

    int minCameraCover(TreeNode* root) {
        if (travel(root) == 1) ret++;
        return ret;
    }
};