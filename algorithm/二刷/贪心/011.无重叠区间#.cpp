/* Ì°ÐÄ */
class Solution {
public:
    static bool cmp(vector<int> p1, vector<int> p2) {
        return p1[0] < p2[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int ret = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
            else {
                ret++;
            }
        }

        return intervals.size() - ret;
    }
};