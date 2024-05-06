/* 超出时间限制（优先级队列） */
class Solution {
public:

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        for (int i = 0; i <= nums.size() - k; i++) {
            priority_queue<int, vector<int>, greater<int>> pri_que;
            for (int j = i; j < i + k; j++) {
                pri_que.push(nums[j]);
            }
            int size = k / 2 - 1 + k % 2;
            while (size--) pri_que.pop();

            if (k % 2 == 0) {
                double p1 = pri_que.top(); pri_que.pop();
                double p2 = pri_que.top(); pri_que.pop();
                double ret = (p1 + p2) / 2;
                result.push_back(ret);
            }
            else {
                double p1 = pri_que.top(); pri_que.pop();
                result.push_back(p1);
            }
        }

        return result;
    }
};