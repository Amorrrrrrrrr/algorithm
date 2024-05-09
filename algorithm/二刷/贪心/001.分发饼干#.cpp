/* 双指针 + 贪心 */
class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {       /* 用大饼干满足胃口大的孩子 */
        sort(g.begin(), g.end(), cmp);
        sort(s.begin(), s.end(), cmp);
        int ret = 0;
        for (int i = 0, j = 0; i < s.size() && j < g.size(); ) {
            if (s[i] >= g[j]) {
                ret++;
                j++;
                i++;
            }
            else {
                j++;
            }
        }

        return ret;
    }
};