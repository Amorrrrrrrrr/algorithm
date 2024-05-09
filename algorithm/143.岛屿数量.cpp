/* 广度优先搜索 */
class Solution {
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

    void bsp(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int,int>> que;
        que.push({x, y});
        visited[x][y] = true;

        while(!que.empty()) {
            int curx = que.front().first;
            int cury = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;    // 越界了，直接跳过
                if (visited[nextx][nexty] == false && grid[nextx][nexty] == '1') {
                    que.push({nextx, nexty});
                    visited[nextx][nexty] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && grid[i][j] == '1') {                                          // 遍历节点
                    result++;
                    bsp(grid, visited, i, j);
                }
            }
        }
        return result;
    }
};


/* 深度优先搜索 */
class Solution {
private:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;    // 越界了，直接跳过
            if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') {                                  // 终止条件写在了循环里面

                visited[nextx][nexty] = true; 
                dfs(grid, visited, nextx, nexty);
            } 
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false)); 

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') { 
                    visited[i][j] = true;                                                               // 当前遍历节点需要手动标为 true
                    result++;                                                                           // 遇到没访问过的陆地，+1
                    dfs(grid, visited, i, j);                                                           // 将与其链接的陆地都标记上 true
                }
            }
        }
        return result;
    }
};