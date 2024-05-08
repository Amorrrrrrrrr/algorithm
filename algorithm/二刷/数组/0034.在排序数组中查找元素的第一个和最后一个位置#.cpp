/* ¶ş·Ö²éÕÒ */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return { -1, -1 };
        if (nums.size() == 1 && nums[0] == target) return { 0, 0 };
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (nums[left] != target) return { -1, -1 };

        for (right = left; right < nums.size(); right++) {
            if (nums[right] != nums[left]) break;
        }

        return { left, right - 1 };

    }
};