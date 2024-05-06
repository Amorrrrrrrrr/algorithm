/* ˫ָ�뷨 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int low = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] == val) continue;
            nums[low] = nums[fast];
            low++;
        }
        return low;
    }
};