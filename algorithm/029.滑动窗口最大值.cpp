class Solution {
public:
    class MyDeque {                                                 /* 单调队列：维护滑动窗口可能的最大值 */
    public:
        void push(int val) {
            while (!myDq.empty() && myDq.back() < val) {            /* 比队尾元素大就移除后插入 */
                myDq.pop_back();
            }
            myDq.push_back(val);
        }

        void pop(int val) {
            if (!myDq.empty() && myDq.front() == val) {             /* 移除队头元素 */
                myDq.pop_front();
            }
        }

        int getMaxValue() {                                         /* 返回队列中维护的最大值 */
            if (!myDq.empty())
                return myDq.front();
            return -1;
        }

        deque<int> myDq;
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyDeque dq;
        vector<int> result;

        for (int i = 0; i < k; i++) {
            dq.push(nums[i]);
        }
        result.push_back(dq.getMaxValue());

        for (int i = k; i < nums.size(); i++) {
            dq.push(nums[i]);
            dq.pop(nums[i - k]);
            result.push_back(dq.getMaxValue());
        }

        return result;
    }
};