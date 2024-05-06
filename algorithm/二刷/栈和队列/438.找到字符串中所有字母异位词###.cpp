class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        if (slen < plen) return {};

        vector<int> ret;

        vector<int> pVec(26, 0);
        vector<int> sVec(26, 0);
        for (int i = 0; i < plen; i++) {
            pVec[p[i] - 'a']++;
            sVec[s[i] - 'a']++;
        }

        if (pVec == sVec) ret.push_back(0);
        for (int j = plen; j < slen; j++) {
            sVec[s[j] - 'a']++;
            sVec[s[j - plen] - 'a']--;

            if (sVec == pVec) ret.push_back(j - plen + 1);
        }

        return ret;
    }
};