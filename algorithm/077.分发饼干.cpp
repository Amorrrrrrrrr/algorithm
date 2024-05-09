class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());                                   /* 排序 */
        sort(s.begin(), s.end());

        int result = 0;
        int index = 0;
        for (int i = 0; i < g.size(); i++) {                        /* 用小饼干来满足小胃口（胃口遍历，饼干动态规划 */
            while (index < s.size()) {
                if (g[i] <= s[index]) {
                    result++;
                    index++;
                    break;
                }
                index++;
            }
        }
        return result;
    }
};