/* 广度优先搜索 */
class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dsp(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
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
                if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1) {
                    que.push({nextx, nexty});
                    visited[nextx][nexty] = true;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            if (visited[i][0] == false && grid[i][0] == 1) {
                dsp(grid, visited, i, 0);
            }
            if (visited[i][n - 1] == false && grid[i][n - 1] == 1) {
                dsp(grid, visited, i, n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (visited[0][j] == false && grid[0][j] == 1) {
                dsp(grid, visited, 0, j);
            }
            if (visited[m - 1][j] == false && grid[m - 1][j] == 1) {
                dsp(grid, visited, m - 1, j);
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

/* 深度优先搜索 */
class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dsp(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;    // 越界了，直接跳过
            if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1) {                                  // 终止条件写在了循环里面

                visited[nextx][nexty] = true; 
                dsp(grid, visited, nextx, nexty);
            } 
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            if (visited[i][0] == false && grid[i][0] == 1) {
                visited[i][0] = true;
                dsp(grid, visited, i, 0);
            }
            if (visited[i][n - 1] == false && grid[i][n - 1] == 1) {
                visited[i][n - 1] = true;
                dsp(grid, visited, i, n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (visited[0][j] == false && grid[0][j] == 1) {
                visited[0][j] = true;
                dsp(grid, visited, 0, j);
            }
            if (visited[m - 1][j] == false && grid[m - 1][j] == 1) {
                visited[m - 1][j] = true;
                dsp(grid, visited, m - 1, j);
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};