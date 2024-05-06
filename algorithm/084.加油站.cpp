/* �����ۼ�ÿ��վ���ʣ��������һ�� curSum < 0 �Ļ�����ѡ����һ��վ����Ϊ��� */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> curSum;
        int totalSum = 0;
        for (int i = 0; i < gas.size(); i++) {                      /* ͳ��ÿ��վ���ʣ���������ܵ�ʣ������ */
            int tmp = gas[i] - cost[i];
            curSum.push_back(tmp);
            totalSum += tmp;
        }
        if (totalSum < 0) return -1;
        
        int index = 0;
        int num = 0;
        for (int i = 0; i < gas.size(); i++) {
            num += curSum[i];
            if (num < 0) {                                          /* ̰���㷨ʵ�� */
                num = 0;
                index = i + 1;
            }
        }
        return index;
    }
};