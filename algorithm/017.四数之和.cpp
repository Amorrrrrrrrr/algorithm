class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && target > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] + nums[i] > target && target > 0) break;                                /* 不能直接 return，尚未遍历完 */
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long)nums[j] + nums[i] + nums[left] + nums[right] > target) {              /* long 避免计算结果超出阈值 */
                        right--;
                    }
                    else if ((long)nums[j] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }

        }
        return result;
    }
};