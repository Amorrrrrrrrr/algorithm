class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
                                                                                    /* dp[i][j]: 以 i-1 为结尾的 nums1 和以 j-1 为结尾的 nums2 
                                                                                       这两个数组的最长重复子数组的长度 
                                                                                    */
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0)); /* dp 数组的第 0 行和第 0 列，无意义，均初始化为 0（如果有意义，需要手动初始化） */
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};