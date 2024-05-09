/* 当两位数不符合要求时，前一位数--，后一位数及后面的取最大值9 */
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string result = to_string(n);
        
        int flag = result.size();                           /* 从当前位往后都变成 9*/
        for (int i = result.size() - 1; i > 0; i--) {       /* 从后向前遍历 */
            if (result[i] < result[i - 1]) {                /* 贪心策略 */
                result[i - 1]--;
                flag = i;
            }
        }

        for (int i = flag; i < result.size(); i++) {
            result[i] = '9';
        }

        return stoi(result);
    }
};