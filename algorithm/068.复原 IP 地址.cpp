class Solution {
public:
    bool isValid(string s, int left, int right) {
        if (left != right && s[left] - '0' == 0) return false;      /* 0 开头数字不合法 */
        if (left > right) return false;                             /* 空数字不合法 */

        int sum = 0;
        while(left <= right) {
            sum = sum * 10 + s[left] - '0';
            if (sum > 255) return false;                             /* 数字 > 255 不合法（循环里防越界） */ 
            left++;
        }

        return true;
    }
    vector<string> result;
    void backTracking(string s, int startIndex, int pointNum) {      /* pointNum 决定递归深度，string 字符串直接原地修改，不需要 path */
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }

        for (int i =  startIndex; i < s.size(); i++) {
            if (!isValid(s, startIndex, i)) {
                continue;
            }
            s.insert(s.begin() + i + 1, '.');
            pointNum++;
            backTracking(s, i + 2, pointNum);
            pointNum--;
            s.erase(s.begin() + i + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backTracking(s, 0, 0);
        return result;
    }
};