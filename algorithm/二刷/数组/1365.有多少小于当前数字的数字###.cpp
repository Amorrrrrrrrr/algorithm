/* 排序 + 哈希表 */
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int hash[101] = { 0 };

        vector<int> ret;
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());                       /* 排序 */
        for (int i = vec.size() - 1; i >= 0; i--) {         /* 从后向前更新哈希表 */
            hash[vec[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            vec[i] = hash[nums[i]];                         /* 记录结果 */
        }

        return vec;
    }
};