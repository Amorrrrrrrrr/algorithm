/* 当连续子序和为负数时就选择下一个数作为新的起点  */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {     
            sum += nums[i];
            if (sum > maxValue) {
                maxValue = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxValue;
    }
};