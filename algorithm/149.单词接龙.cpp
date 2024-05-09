/* 广度优先搜索 */
/* 无向图求最短路，广搜最为合适，广搜只要搜到了终点，那么一定是最短的路径 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        queue<string> que;
        unordered_map<string, int> visited;                                         /* 记录遍历过的 word <word, 查询到这个 word 路径长度> */ 
        que.push(beginWord);
        visited.insert(pair<string,int>(beginWord, 1));
        
        while (!que.empty()) {
            string curWord = que.front();
            que.pop();
            int path = visited[curWord];                                            /* 这个word的路径长度 */
            for (int i = 0; i < curWord.size(); i++) {                  
                string newWord = curWord;
                for (int j = 0; j < 26; j++) {                                      /* 每次置换一个字母 */
                    newWord[i] = 'a' + j;
                    if (newWord == endWord) return path + 1;                        /* 终止条件 */
                    if (wordSet.find(newWord) == wordSet.end() || visited.find(newWord) != visited.end()) continue;
                    
                    que.push(newWord);
                    visited.insert(pair<string,int>(newWord, path + 1));            /* 添加遍历过的 word */
                }
            }
        }
        return 0;
    }
};