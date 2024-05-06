/* 不断累加每个站点的剩余油量，一旦 curSum < 0 的话，就选择下一个站点作为起点 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> curSum;
        int totalSum = 0;
        for (int i = 0; i < gas.size(); i++) {                      /* 统计每个站点的剩余油量和总的剩余油量 */
            int tmp = gas[i] - cost[i];
            curSum.push_back(tmp);
            totalSum += tmp;
        }
        if (totalSum < 0) return -1;
        
        int index = 0;
        int num = 0;
        for (int i = 0; i < gas.size(); i++) {
            num += curSum[i];
            if (num < 0) {                                          /* 贪心算法实现 */
                num = 0;
                index = i + 1;
            }
        }
        return index;
    }
};