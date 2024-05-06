/* ���ֲ��ҷ� */
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        vector<pair<int, int>> startIntervals;
        for (int i = 0; i < intervals.size(); i++) {
            startIntervals.push_back(pair<int, int>(intervals[i][0], i));
        }
        sort(startIntervals.begin(), startIntervals.end());                     /* vector �з����ֵ��Ҳ����ֱ������ */

        vector<int> ret(intervals.size(), -1);

        for (int i = 0; i < intervals.size(); i++) {
            int left = 0;
            int right = intervals.size() - 1;
            int cur = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (intervals[i][1] > startIntervals[mid].first) left = mid + 1;
                else if (intervals[i][1] <= startIntervals[mid].first) {        /* ���ֲ��ҹ��� */
                    cur = mid;
                    right = mid - 1;
                }

            }
            if (cur != -1) ret[i] = startIntervals[cur].second;
        }

        return ret;
    }
};