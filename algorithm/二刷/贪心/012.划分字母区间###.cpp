/* 哈希表 */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }

        vector<int> ret;
        int right = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if (right == i) {
                ret.push_back(right - left + 1);        /* 左右指针求区间大小 */
                left = right + 1;
            }
        }
        return ret;
    }
};