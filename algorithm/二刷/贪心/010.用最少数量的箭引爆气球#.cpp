/* Ì°ÐÄ */
class Solution {
public:
    static bool cmp(vector<int> p1, vector<int> p2) {
        return p1[0] < p2[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

        int ret = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= points[i - 1][1]) {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
            else {
                ret++;
            }
        }

        return ret;
    }
};