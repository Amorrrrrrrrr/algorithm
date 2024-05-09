/* 排序 + 去重 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(const vector<int>& nums, int startIndex, vector<bool> used) {
        result.push_back(path);
        if (startIndex == nums.size()) return;

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) continue;

            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), 0);
        backTracking(nums, 0, used);
        return result;
    }
};