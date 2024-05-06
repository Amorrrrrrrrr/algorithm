/* 二分查找法 */
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ret = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x) {
                ret = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ret;
    }
};