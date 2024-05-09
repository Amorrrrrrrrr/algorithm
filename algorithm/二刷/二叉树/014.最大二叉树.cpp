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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);

        int maxValue = -1;
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                index = i;
            }
        }

        TreeNode* cur = new TreeNode(nums[index]);
        vector<int> left(nums.begin(), nums.begin() + index);
        vector<int> right(nums.begin() + index + 1, nums.end());
        cur->left = constructMaximumBinaryTree(left);
        cur->right = constructMaximumBinaryTree(right);

        return cur;
    }
};