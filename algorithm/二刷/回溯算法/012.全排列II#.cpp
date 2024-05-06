class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            if (uset.find(nums[i]) != uset.end()) continue;         /* 直接使用 uset 去重，无需排序 */

            used[i] = true;
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};