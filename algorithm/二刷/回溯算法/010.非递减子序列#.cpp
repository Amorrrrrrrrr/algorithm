/* 非递减子序列 = 单调递增 = 排序 -> 所以子集没有重复的 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() >= 2)                                           /* 终止条件 */
            result.push_back(path);                                          

        if (startIndex == nums.size()) return;

        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if (uset.find(nums[i]) != uset.end()) continue;
            if (!path.empty() && nums[i] < path.back()) continue;       /* 非递减子序列判断条件 */

            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};