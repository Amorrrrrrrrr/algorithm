/* 双指针法 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;                                          /* 去重逻辑：记得 j > i + 1 */
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;          /* long long 防止溢出 */
                    else if ((long long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;                                                                    /* 先移动指针，再进行去重 */
                        while (left < right && nums[right] == nums[right + 1]) right--;                     /* 双指针的树层去重 */
                        while (left < right && nums[left] == nums[left - 1]) left++;
                    }
                }
            }
        }
        return result;
    }
};