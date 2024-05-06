/* 分割回文串本质上是分割符的组合 */

class Solution {
public:
    bool isPal(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] == s[right]) {
                left++; right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> result;
    vector<string> path;
    void backTracking(const string& s, int startIndex) {                    /* startIndex 不仅用于组合，而且表示分割符 */
        if (startIndex == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {                       /* [0, size() - 1] 分割符的区间 */
            if (!isPal(s, startIndex, i)) continue;                         /* s[startIndex, i] 是分割的子串*/

            path.push_back(s.substr(startIndex, i - startIndex + 1));
            backTracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return result;
    }
};