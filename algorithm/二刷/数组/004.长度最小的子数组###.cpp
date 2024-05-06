/* 双指针法（滑动窗口思想） */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0;
        int sum = 0;
        int ret = INT_MAX;
        for (int fast = 0; fast < nums.size(); fast++) {
            sum += nums[fast];
            while (sum >= target) {
                ret = min(ret, fast - slow + 1);
                sum -= nums[slow];
                slow++;
            }
        }
        if (ret == INT_MAX) return 0;
        return ret;

    }
};

/* 滑动窗口的精妙之处在于根据当前子序列和大小的情况，不断调节子序列的起始位置。从而将O(n^2)暴力解法降为O(n)。 */