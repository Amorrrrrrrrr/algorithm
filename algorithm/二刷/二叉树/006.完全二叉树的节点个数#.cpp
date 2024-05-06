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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;             /* 终止条件为空节点和满二叉树 */
        int left = 0, right = 0;
        TreeNode* leftNode = root;
        TreeNode* rightNode = root;
        while (leftNode = leftNode->left) {
            left++;
        }
        while (rightNode = rightNode->right) {
            right++;
        }
        if (left == right) return pow(2, left + 1) - 1;

        int leftSum = countNodes(root->left);
        int rightSum = countNodes(root->right);
        return leftSum + rightSum + 1;
    }
};