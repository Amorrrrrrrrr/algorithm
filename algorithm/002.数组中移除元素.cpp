#include <vector>
/* 双指针思路：
   - 快指针：寻找新数组所需要的元素         (遍历旧数组)
   - 慢指针：新数组对应的下标               (保存新数组)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};