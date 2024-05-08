class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        int leftNum = 0;
        int rightNum = sum - nums[0];
        if (leftNum == rightNum) return 0;
        for (int i = 1; i < nums.size(); i++) {
            leftNum += nums[i - 1];
            rightNum = sum - leftNum - nums[i];
            if (leftNum == rightNum) return i;
        }
        return -1;
    }
};