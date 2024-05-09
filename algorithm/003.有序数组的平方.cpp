#include <vector>
/* 双指针思路：最大值永远位于数组的两端 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int k = nums.size() - 1;

        int left = 0;
        int right = k;
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                result[k] = nums[right] * nums[right];
                k--;
                right--;
            } else {
                result[k] = nums[left] * nums[left];
                k--;
                left++;
            }
        }
        return result;
    }
};