#include <vector>
/* 1.左闭右闭区间:[left, right] */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {                          /* 注意点1：要求合法区间 */
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;                     /* 注意点2：搜索区间 */
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] == target) {
                return middle;
            }
        }
        return -1;
    }
};


/* 2.左闭右开区间:[left, right) */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] == target) {
                return middle;
            }
        }
        return -1;
    }
};