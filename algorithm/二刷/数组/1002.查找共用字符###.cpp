/* ¹þÏ£±í */
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int hash[26] = { 0 };
        for (int i = 0; i < words[0].size(); i++) {
            hash[words[0][i] - 'a']++;
        }

        int hashtmp[26] = { 0 };
        for (int i = 1; i < words.size(); i++) {
            memset(hashtmp, 0, 26 * sizeof(int));
            for (int j = 0; j < words[i].size(); j++) {
                hashtmp[words[i][j] - 'a']++;
            }

            for (int k = 0; k < 26; k++) {
                hash[k] = min(hash[k], hashtmp[k]);
            }
        }

        vector<string> ret;
        for (int i = 0; i < 26; i++) {
            while (hash[i] >= 1) {
                char c = 'a' + i;
                ret.push_back(string(1, c));
                hash[i]--;
            }
        }

        return ret;
    }
};