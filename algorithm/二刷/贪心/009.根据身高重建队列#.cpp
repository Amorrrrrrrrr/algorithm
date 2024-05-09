/* 贪心 */
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result;
        for (int i = 0; i < people.size(); i++) {                           /* 直接插入到新的数组 */
            result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }
};