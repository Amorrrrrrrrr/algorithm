/* 贪心 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> chazhi;
        int chazhiNum = 0;
        for (int i = 0; i < gas.size(); i++) {
            int tmp = gas[i] - cost[i];
            chazhi.push_back(tmp);
            chazhiNum += tmp;
        }
        if (chazhiNum < 0) return -1;
        int index = 0;
        int num = 0;
        for (int i = 0; i < gas.size(); i++) {
            num += chazhi[i];
            if (num < 0) {
                num = 0;
                index = i + 1;                          /* index 为不符合条件的下一个，即第一个符合条件的 */
            }
        }
        return index;
    }
};