/* ˫ָ�뷨 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int cur = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                result[cur] = nums[right] * nums[right];
                right--;
                cur--;
            }
            else {
                result[cur] = nums[left] * nums[left];
                left++;
                cur--;
            }
        }

        return result;
    }
};