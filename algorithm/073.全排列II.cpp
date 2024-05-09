/* 树枝去重 + 树层去重*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(const vector<int>& nums, vector<bool> used) { 
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && 0 == used[i - 1]) continue;  /* 树层去重（ 1 == used[i - 1] 也可以 --> 树枝去重 ） */
            if (used[i] == true) continue;                                      /* used 数组记录 path 里面用过了哪些元素，可用于树枝去重 */

            used[i] = true;
            path.push_back(nums[i]);
            backTracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());                                         /* 排序 */

        vector<bool> used(nums.size(), 0);
        backTracking(nums, used);
        return result;
    }
};