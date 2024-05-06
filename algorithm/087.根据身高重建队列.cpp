/* 先确定一个维度，再确定另一个维度 */
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {           
        if (a[0] == b[0]) return a[1] < b[1];                           /* 次要排序 */
        return a[0] > b[0];                                             /* 主要排序 */
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result;                                     /* 不能原地修改，会出问题 */
        for (int i = 0; i < people.size(); i++) {
            result.insert(result.begin() + people[i][1], people[i]);    /* 贪心策略(插入元素前面的所有元素都比它大(>=)) */
        }
        return result;
    }
};


/* 链表优化 vector */