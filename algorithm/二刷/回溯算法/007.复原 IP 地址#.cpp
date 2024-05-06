class Solution {
public:
    bool isValid(const string& s, int left, int right) {
        if (left > right) return false;
        if (left < right && s[left] == '0') return false;

        int sum = 0;
        for (int i = left; i <= right; i++) {
            if (s[i] < 0 && s[i] > 9) return false;
            sum = sum * 10 + s[i] - '0';
            if (sum > 255) return false;
        }
        return true;
    }

    vector<string> result;
    void backtracking(string& s, int index, int point) {    /* 数量限制 */
        if (point == 3) {
            if (isValid(s, index, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (!isValid(s, index, i)) continue;
            point++;
            s.insert(s.begin() + i + 1, '.');               /* 原地修改 */
            backtracking(s, i + 2, point);
            point--;
            s.erase(s.begin() + i + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};