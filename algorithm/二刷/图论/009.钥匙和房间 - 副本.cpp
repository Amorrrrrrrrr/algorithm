/* 层序遍历 */
class Solution {
public:
    bool bfs(vector<vector<int>>& rooms, unordered_set<int>& uset, int index) {
        queue<int> que;
        que.push(index);
        uset.insert(index);
        while (!que.empty()) {
            int cur = que.front();que.pop();
            for (int i = 0; i < rooms[cur].size(); i++) {
                if (uset.find(rooms[cur][i]) == uset.end()) {
                    que.push(rooms[cur][i]);
                    uset.insert(rooms[cur][i]);
                    if (uset.size() == rooms.size()) return true;
                }
            }
        }
        return false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> uset;
        return bfs(rooms, uset, 0);
    }
};

/* 深度优先遍历 */
class Solution {
public:
    bool dfs(vector<vector<int>>& rooms, unordered_set<int>& uset, int index) {
        if (uset.size() == rooms.size()) return true;

        for (int i = 0; i < rooms[index].size(); i++) {
            if (uset.find(rooms[index][i]) != uset.end()) continue;             /* 跳过访问过的房间 */
            
            uset.insert(rooms[index][i]);                                       /* 记录可以访问的房间 */
            if(dfs(rooms, uset, rooms[index][i])) return true;
                                                                                /* 因为不是记录访问过的房间，因此不用回溯 */
        }
        return false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> uset;
        uset.insert(0);
        return dfs(rooms, uset, 0);
    }
};