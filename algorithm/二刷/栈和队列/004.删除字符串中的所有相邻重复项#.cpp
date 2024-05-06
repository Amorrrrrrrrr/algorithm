class Solution {
public:
    string removeDuplicates(string s) {
        string ret;                                         /* ÓÃ×Ö·û´®Ä£ÄâÕ» */
        for (int i = 0; i < s.size(); i++) {
            if (ret.empty()) ret.push_back(s[i]);
            else {
                if (ret.back() == s[i]) ret.pop_back();
                else ret.push_back(s[i]);
            }
        }
        return ret;
    }
};