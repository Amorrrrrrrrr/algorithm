class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());                                                 /* 只适用于排序后的容器 */

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return result;                                             /* 剪枝 */
            if (i > 0 && (nums[i] == nums[i - 1])) {                                    /* if + continue 去重 */
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {              /* 结果容器中不包含重复元素 */
                        left++;                                                         /* 先去重，再操作双指针 */
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};