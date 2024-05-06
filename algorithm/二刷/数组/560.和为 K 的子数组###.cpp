/* 枚举（超出时间限制） */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {     /* 以 start 结尾的子数组是否满足条件 */
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

/* 哈希表 + 前缀和 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;                                           /* <以 i 为尾的数组的和, 和的个数> */
        umap[0] = 1;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (umap.find(sum - k) != umap.end()) ret += umap[sum - k];         /* 前缀和的使用 */
            umap[sum]++;                                                        /* 先使用后添加，保证子数组的存在 */
        }
        return ret;
    }
};