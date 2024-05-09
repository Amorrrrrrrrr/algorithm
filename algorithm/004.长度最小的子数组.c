/* 滑动窗口思想：遍历滑动窗口终止位置，动态调整滑动窗口起始位置 */
int minSubArrayLen(int target, int* nums, int numsSize) {
    int right;
    int left = 0;
    int sum = 0;
    int len;
    int minLen = INT_MAX;
    for (right = 0; right < numsSize; right++) {
        sum += nums[right];                     
        while (sum >= target) {                     /* 动态调整条件 */
            len = right - left + 1;
            minLen = len < minLen ? len : minLen;
            sum -= nums[left++];
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}