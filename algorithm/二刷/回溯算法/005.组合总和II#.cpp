class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, vector<bool> next, int startIndex) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && next[i - 1] == false) continue;

            sum += candidates[i];
            path.push_back(candidates[i]);
            next[i] = true;
            backtracking(candidates, target, sum, next, i + 1);
            next[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> next(candidates.size(), false);
        backtracking(candidates, target, 0, next, 0);
        return result;
    }
};