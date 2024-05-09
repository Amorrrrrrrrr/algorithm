/* 无重叠区间问题 */
class Solution {
    static bool cmp(vector<int> p1, vector<int> p2) {
        return p1[0] < p2[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), cmp);

        int result = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                result++;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }
        return result;
    }
};