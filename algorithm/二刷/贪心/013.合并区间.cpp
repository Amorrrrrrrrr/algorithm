/* Ì°ÐÄ */
class Solution {
public:
    static bool cmp(vector<int> p1, vector<int> p2) {
        return p1[0] < p2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ret.back()[1]) {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
            else {
                ret.push_back(intervals[i]);
            }
        }

        return ret;
    }
};