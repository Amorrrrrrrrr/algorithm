class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));     /* dp[i][j]: 以 [0,i-1] 的 text1 和 以 [0,j-1] 的 text2 
                                                                                           这两个数组的最长公共子序列的长度 
                                                                                        */
        
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);                         /* 不相等时的递推公式 */
                }
            }
        }
        return dp[nums1.size()][nums2.size()];                                          /* 直接返回二维数组的最后一个元素即可 */
    }
};