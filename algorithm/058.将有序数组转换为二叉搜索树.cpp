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

/* 前序遍历 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;

        int middle = (0 + nums.size()) / 2;
        TreeNode* cur = new TreeNode(nums[middle]);
        if (nums.size() == 1) return cur;

        vector<int> left(nums.begin(), nums.begin() + middle);
        vector<int> right(nums.begin() + middle + 1, nums.end());
        cur->left = sortedArrayToBST(left);
        cur->right = sortedArrayToBST(right);
        return cur;
    }
};

/* 双指针优化 */
class Solution {
public:
    TreeNode* travel(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;

        int middle = (left + right) / 2;
        TreeNode* cur = new TreeNode(nums[middle]);
        if (nums.size() == 1) return cur;

        cur->left = travel(nums, left, middle - 1);
        cur->right = travel(nums, middle + 1, right);
        return cur;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return travel(nums, 0, nums.size() - 1);
    }
};