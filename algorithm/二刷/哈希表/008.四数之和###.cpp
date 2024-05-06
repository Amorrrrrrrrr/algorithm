/* ˫ָ�뷨 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;                                          /* ȥ���߼����ǵ� j > i + 1 */
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;          /* long long ��ֹ��� */
                    else if ((long long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;                                                                    /* ���ƶ�ָ�룬�ٽ���ȥ�� */
                        while (left < right && nums[right] == nums[right + 1]) right--;                     /* ˫ָ�������ȥ�� */
                        while (left < right && nums[left] == nums[left - 1]) left++;
                    }
                }
            }
        }
        return result;
    }
};