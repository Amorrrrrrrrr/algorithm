/* 当 (nums[right] - nums[cur]) * (nums[cur] - nums[left]) < 0 时，cur 是一个摆动节点 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;                                            
        if (nums.size() == 2) {                                                          /* 情况 1 */
            if (nums[0] == nums[1]) return 1;
            return 2;
        }
        int left = 0;
        int cur = 1;
        int right = 2;
        int result = 0;
        while (right < nums.size()) {
            if ((nums[right] - nums[cur]) * (nums[cur] - nums[left]) < 0) {
                result++;
                left = cur; cur = right; right++;
            } else if ((nums[right] - nums[cur]) * (nums[cur] - nums[left]) > 0) {       /* 情况 2 */
                left = cur; cur = right; right++;
            } else {
                while(nums[right] == nums[cur]) {                                        /* 情况 3（右平坡） */
                    right++;
                }
                while(nums[left] == nums[cur]) {                                         /* 情况 4（左平坡，理论上只有刚开始会出现） */
                    left = cur; cur = right; right++;
                }
            }
        }
        if (result == 0 && nums[0] == nums[nums.size() - 1]) return 1；                                                               /* 情况 5（纯平坡） */

        return result + 2;
    }
};