/* 层序遍历 */
class Solution {
public:
    bool isValid(string s, string t) {
        int size = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) size++;
        }
        if (size == 1) return true;
        return false;
    }

    unordered_map<string,int> bfs(vector<string>& wordList, vector<bool>& visited, string beginWord, string endWord) {
        queue<string> que;
        unordered_map<string,int> umap;                     /* 记录每个字符串属于哪一层 */
        que.push(beginWord);
        int path = 1;
        umap[beginWord] = 1;
        while (!que.empty()) {
            int size = que.size();
            path++;
            while (size--) {
                string cur = que.front(); que.pop();
                if (cur == endWord) return umap;
                for (int i = 0; i < wordList.size(); i++) {
                    if (isValid(wordList[i], cur) && visited[i] == false) {
                        que.push(wordList[i]);
                        umap[wordList[i]] = path;
                        visited[i] = true;
                    }
                }
            }
            
        }
        return {pair<string,int>("", 0)};
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        unordered_map<string,int> umap = bfs(wordList,visited,beginWord,endWord);
        if (umap.find("") != umap.end()) return 0;
        return umap[endWord];
    }
};