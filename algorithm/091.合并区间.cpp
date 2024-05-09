/* 重叠区间问题 */
class Solution {
    static bool cmp(vector<int> p1, vector<int> p2) {
        return p1[0] < p2[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> result;
        result.push_back(intervals[0]);                                     /* 直接添加、比较和合并结果集 */
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};