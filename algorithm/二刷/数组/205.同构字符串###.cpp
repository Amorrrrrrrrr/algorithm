/* ¹þÏ£±í(Ó³Éä) */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> maps;
        unordered_map<char, char> mapt;
        for (int i = 0; i < s.size(); i++) {
            if (maps.find(s[i]) == maps.end()) {
                maps[s[i]] = t[i];
            }
            if (mapt.find(t[i]) == mapt.end()) {
                mapt[t[i]] = s[i];
            }

            if (maps[s[i]] != t[i] || mapt[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};