class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[slow] != nums[fast]) {                 /* 先++，再赋值 */
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};