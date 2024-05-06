/* Ë«Ö¸Õë + »¬¶¯´°¿Ú */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> uset;
        int ret = 0;

        int slow = 0;
        int fast = 0;
        for (; fast < s.size(); fast++) {
            if (!uset.empty() && uset.find(s[fast]) != uset.end()) {

                while (s[slow] != s[fast]) {
                    uset.erase(s[slow]);
                    slow++;
                }
                uset.erase(s[slow]);
                slow++;
            }
            uset.insert(s[fast]);
            ret = max(ret, fast - slow + 1);
        }
        return ret;
    }
};