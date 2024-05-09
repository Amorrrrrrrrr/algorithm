class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int bsp(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int,int>> que;
        que.push(pair<int,int>(x, y));
        visited[x][y] = true;
        int area = 1;
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
                        area++;
                    }
                }
            }
        }
        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));                            /* 用 visited 记录岛屿是否遍历过 */

        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                                                   /* 遍历岛屿，记录岛屿数量 */
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    ret = max(ret, bsp(grid,visited,i,j));
                }
            }
        }
        return ret;
    }
};