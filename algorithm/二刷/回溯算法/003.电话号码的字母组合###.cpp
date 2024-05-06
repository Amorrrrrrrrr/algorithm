class Solution {
public:
    string str[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> result;
    string path;
    void backtracking(string digits, int index) {           /* 需要遍历每一个元素 */
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        int curIndex = digits[index] - '0';                 
        string s = str[curIndex];                           
        for (int j = 0; j < s.size(); j++) {                /* 处理当前集合 */
            path.push_back(s[j]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        backtracking(digits, 0);
        return result;
    }
};