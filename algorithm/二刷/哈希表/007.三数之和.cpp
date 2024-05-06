/* ˫ָ�뷨 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;                          /* ����ȥ�� */
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while (right > left && nums[right] == nums[right - 1]) right--; /* ˫ָ�������ȥ�� */
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    left++; right--;
                }
            }
        }
        return result;
    }
};