/* 广度优先搜索 */
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> que;
        que.push(0);
        visited[0] = true;
        while (!que.empty()) {
            int index = que.front();que.pop();
            for (int i = 0; i < rooms[index].size(); i++) {
                int key = rooms[index][i];                          /* 房间内所有的钥匙 */
                if (visited[key] == false) {
                    que.push(key);
                    visited[key] = true;
                }
            }
        }

        for (int i = 0; i < rooms.size(); i++) {
            if (visited[i] == false) return false;
        }
        return true;
    }
};