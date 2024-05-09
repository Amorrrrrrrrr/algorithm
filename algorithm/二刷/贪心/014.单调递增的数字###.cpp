/* Ì°ĞÄ */
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int index = -1;
        string str = to_string(n);
        string tmp = str;
        for (int i = tmp.size() - 2; i >= 0; i--) {
            if (tmp[i] > tmp[i + 1]) {
                index = i;
                tmp[i]--;
            }
        }

        if (index == -1) return n;
        str[index]--;
        for (int i = index + 1; i < str.size(); i++) {
            str[i] = '9';
        }

        return stoi(str);
    }
};