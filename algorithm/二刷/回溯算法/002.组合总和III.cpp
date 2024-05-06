class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            int sum = 0;
            for (int i = 0; i < path.size(); i++) {
                sum += path[i];
            }
            if (sum == n) {
                result.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1);
        return result;
    }
};