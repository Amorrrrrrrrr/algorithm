/* 去重分为树层去重和树枝去重 */

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(const vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {          /* 树层去重 */
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backTracking(candidates, target, sum, i + 1, used);
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());                                             /* 排序 */

        vector<bool> used(candidates.size(), false);                                            /* 树层去重使用 used 数组 */
        backTracking(candidates, target, 0, 0, used);
        return result;
    }
};