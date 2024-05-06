class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> findStrs = strs;
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < findStrs.size(); i++) {
            sort(findStrs[i].begin(), findStrs[i].end());
            umap[findStrs[i]].push_back(strs[i]);                   /* 排序并加入到哈希表中 */
        }

        vector<vector<string>> ret;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            ret.push_back(it->second);
        }
        return ret;
    }
};