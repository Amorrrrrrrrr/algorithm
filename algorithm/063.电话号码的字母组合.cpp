/* 不同集合间组合 */
class Solution {
public:
    string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> result;
    string path;
    void backTracking(const string& digits, int index) {    /* 传引用效率高 */
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        string str = letterMap[digits[index] - '0'];
        for (int i = 0; i < str.size(); i++) {
            path.push_back(str[i]);
            backTracking(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string> {};
        backTracking(digits, 0);
        return result;
    }
};