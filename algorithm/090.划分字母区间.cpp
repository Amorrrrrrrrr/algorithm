class Solution {
public:
    vector<int> partitionLabels(string s) {
        int vec[27] = {0};
        for (int i = 0; i < s.size(); i++) {            /* 哈希表记录元素最后出现的位置 */
            vec[s[i] - 'a'] = i;
        }

        vector<int> result;
        int left = 0, right = 0;                        /* 双指针表示区间 */
        for (int i = 0; i < s.size(); i++) {            
            right = max(vec[s[i] - 'a'], right);
            if (i == right) {                           /* 贪心策略 */
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return result;
    }
};