/* 一旦当前覆盖范围到尽头还没有到终点，我们就启动下一步的覆盖范围*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int next = nums[0];
        if (next >= nums.size() - 1) return 1;
        int maxNext = 0;
        int step = 1;
        for (int i = 0; i <= next; i++) {
            maxNext = max(maxNext, i + nums[i]);
            if (i == next) {
                if (maxNext >= nums.size() - 1) return step + 1;
                else if (maxNext > next) {
                    step++;
                    next = maxNext;
                } else {
                    return false;
                }
            }

        }
        return step;                                                /* 实际不会到达这里 */
    }
};