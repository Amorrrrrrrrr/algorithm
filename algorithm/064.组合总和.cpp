class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) return;                                                               /* 递归深度取决于 target */
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {                                  
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, sum, i);                                           /* startIndex = i 表示可重复选取 */
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0, 0);
        return result;
    }
};

/* 排序 + 广度剪枝优化 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) { /* 广度剪枝优化 */                          
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());                                             /* 排序 */
        backTracking(candidates, target, 0, 0);
        return result;
    }
};