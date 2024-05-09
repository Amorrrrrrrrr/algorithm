/* 广度优先搜索 */
class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int bsp(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int,int>> que;
        que.push({x, y});
        visited[x][y] = true;
        int area = 1;
        while (!que.empty()) {
            int curx = que.front().first;
            int cury = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
                if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1) {
                    que.push({nextx, nexty});
                    visited[nextx][nexty] = true;
                    area++;
                }
            }
        }
        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && grid[i][j] == 1) {
                    result = max(result, bsp(grid, visited, i, j));
                }
            }
        }
        return result;
    }
};