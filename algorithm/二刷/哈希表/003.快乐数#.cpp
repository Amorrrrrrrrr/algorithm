class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset;                            
        while (n != 1) {                                    /* while 中写循环继续的条件 */
            if (uset.find(n) != uset.end()) return false;
            uset.insert(n);
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);                 /* 运算符的优先级 */
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};