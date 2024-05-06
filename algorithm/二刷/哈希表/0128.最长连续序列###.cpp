class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            uset.insert(nums[i]);
        }

        int ret = 0;
        for (auto it = uset.begin(); it != uset.end(); it++) {
            int num = *it;
            if (uset.find(num - 1) == uset.end()) {                 /* 去重：不是起始节点不找 */
                int maxLen = 1;
                while (uset.find(num + 1) != uset.end()) {
                    maxLen++;
                    num++;
                }

                ret = max(maxLen, ret);
            }
        }

        return ret;
    }
};