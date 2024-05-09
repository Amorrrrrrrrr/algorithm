/* 重叠区间问题 */
class Solution {
    static bool cmp(vector<int> p1, vector<int> p2) {
        return p1[0] < p2[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;                           /* 排序 */

        sort(points.begin(), points.end(), cmp);

        int result = 1;
        for (int i = 1; i < points.size(); i++) {                   /* 遍历 */
            if (points[i][0] > points[i - 1][1]) {                  /* 重叠区间比较策略 */
                result++;
            } else {
                points[i][1] = min(points[i - 1][1], points[i][1]); 
            }
        }
        return result;
    }
};