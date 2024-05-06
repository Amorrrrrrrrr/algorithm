class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        if (startIndex == nums.size()) return;

        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if (uset.find(nums[i]) != uset.end()) continue;

            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());                             /* 无论是组合还是子集问题，无论是使用 used 还是 uset，
                                                                       去重需要排序
                                                                    */
        backtracking(nums, 0);
        return result;
    }
};