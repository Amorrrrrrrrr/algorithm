class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void bsp(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int,int>> que;
        que.push(pair<int,int>(x, y));
        visited[x][y] = true;
        while (!que.empty()) {
            pair<int,int> cur = que.front();que.pop();
            int curx = cur.first;
            int cury = cur.second;
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < grid.size() && nextx >= 0 &&
                        nexty < grid[0].size() && nexty >= 0) {
                    if (grid[nextx][nexty] == 1 && visited[nextx][nexty] == false){
                        que.push(pair<int,int>(nextx, nexty));
                        visited[nextx][nexty] = true;
                    }
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));                            

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && visited[i][0] == false) bsp(grid, visited, i, 0);                /* 注意只有陆地才广搜 */
            if (grid[i][n - 1] == 1 && visited[i][n - 1] == false) bsp(grid, visited, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && visited[0][j] == false) bsp(grid, visited, 0, j);
            if (grid[m - 1][j] == 1 && visited[m - 1][j] == false) bsp(grid, visited, m - 1, j);
        }

        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    ret++;
                }
            }
        }
        return ret;
    }
};