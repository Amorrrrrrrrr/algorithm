/* ȥ�ط�Ϊ����ȥ�غ���֦ȥ�� */

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
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {          /* ����ȥ�� */
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
        sort(candidates.begin(), candidates.end());                                             /* ���� */

        vector<bool> used(candidates.size(), false);                                            /* ����ȥ��ʹ�� used ���� */
        backTracking(candidates, target, 0, 0, used);
        return result;
    }
};