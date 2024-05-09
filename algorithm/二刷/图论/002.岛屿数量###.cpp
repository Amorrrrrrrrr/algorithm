
class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {     /* 广搜模版 */
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
                    if (grid[nextx][nexty] == '1' && visited[nextx][nexty] == false){
                        que.push(pair<int,int>(nextx, nexty));
                        visited[nextx][nexty] = true;
                    }
                }

            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));                            /* 用 visited 记录岛屿是否遍历过 */

        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                                                   /* 遍历岛屿，记录岛屿数量 */
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    bfs(grid, visited, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
};