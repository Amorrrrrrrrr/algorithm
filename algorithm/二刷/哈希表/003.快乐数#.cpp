class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset;                            
        while (n != 1) {                                    /* while ��дѭ������������ */
            if (uset.find(n) != uset.end()) return false;
            uset.insert(n);
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);                 /* ����������ȼ� */
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};