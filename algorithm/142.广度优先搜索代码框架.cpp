int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 表示四个方向

// grid 是地图，也就是一个二维数组
// visited标记访问过的节点，不要重复访问
// x,y 表示开始搜索节点的下标

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;                                                                           // 只要加入队列，立刻标记为访问过的节点
    while(!que.empty()) {
        pair<int ,int> cur = que.front(); que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (int i = 0; i < 4; i++) {                                                               // 开始向当前节点的四个方向左右上下去遍历
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;// 坐标越界了，直接跳过
            if (!visited[nextx][nexty]) {
                que.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
    }

}