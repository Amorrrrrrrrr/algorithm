/* ¹þÏ£±í */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<string, int> umap;

        for (int i = 0; i <= s.size() - 10; i++) {
            umap[s.substr(i, 10)]++;
        }

        vector<string> result;

        for (unordered_map<string, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            if ((*it).second >= 2) result.push_back((*it).first);
        }

        return result;
    }
};