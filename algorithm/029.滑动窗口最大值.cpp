class Solution {
public:
    class MyDeque {                                                 /* �������У�ά���������ڿ��ܵ����ֵ */
    public:
        void push(int val) {
            while (!myDq.empty() && myDq.back() < val) {            /* �ȶ�βԪ�ش���Ƴ������ */
                myDq.pop_back();
            }
            myDq.push_back(val);
        }

        void pop(int val) {
            if (!myDq.empty() && myDq.front() == val) {             /* �Ƴ���ͷԪ�� */
                myDq.pop_front();
            }
        }

        int getMaxValue() {                                         /* ���ض�����ά�������ֵ */
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