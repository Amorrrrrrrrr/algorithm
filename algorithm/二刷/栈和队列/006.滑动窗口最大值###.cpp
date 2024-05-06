class Solution {
public:
    class MyDeque {
    public:
        void push(int value) {
            while (!dq.empty() && value > dq.back()) {      /* while */
                dq.pop_back();
            }
            dq.push_back(value);

        }

        void pop(int val) {
            if (!dq.empty() && val == dq.front()) {         /* if */
                dq.pop_front();
            }
        }

        int getMaxValue() {
            return dq.front();
        }

        deque<int> dq;
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyDeque dp;
        vector<int> result;

        for (int i = 0; i < k; i++) {
            dp.push(nums[i]);
        }
        result.push_back(dp.getMaxValue());

        for (int i = k; i < nums.size(); i++) {
            dp.pop(nums[i - k]);
            dp.push(nums[i]);
            result.push_back(dp.getMaxValue());
        }

        return result;
    }
};