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

/* ǰ����� */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {                                         /* ��ֹ���� */
            return NULL;
        }

        TreeNode* cur = new TreeNode();                                 /* �� */
        int maxValue = INT_MIN;
        int maxIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (maxValue < nums[i]) {
                maxValue = nums[i];
                cur->val = nums[i];
                maxIndex = i;
            }
        }
        if (nums.size() == 1) {                                        /* ��ֹ���� */
            return cur;
        }

        vector<int> left(nums.begin(), nums.begin() + maxIndex);        /* �������±���洴�������飬Ч�ʸ��� */
        vector<int> right(nums.begin() + maxIndex + 1, nums.end());
        cur->left = constructMaximumBinaryTree(left);
        cur->right = constructMaximumBinaryTree(right);
        return cur;
    }
};