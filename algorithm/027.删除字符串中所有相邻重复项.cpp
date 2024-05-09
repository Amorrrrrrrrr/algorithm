class Solution {
public:
    string removeDuplicates(string s) {
        string result;                                      /* 用字符串来模拟栈，字符串头为栈底，字符串尾为栈顶 */
        for (int i = 0; i < s.size(); i++) {
            if (result.empty() || s[i] != result.back()) {
                result.push_back(s[i]);
            } else {
                result.pop_back();
            }
        }
        return result;
    }
};