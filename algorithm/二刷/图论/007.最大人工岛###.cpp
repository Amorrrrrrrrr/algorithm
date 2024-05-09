class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int index) {
        queue<pair<int,int>> que;
        que.push(pair<int,int>(x, y));
        visited[x][y] = index;
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
                    if (grid[nextx][nexty] == 1 && visited[nextx][nexty] == 0){
                        que.push(pair<int,int>(nextx, nexty));
                        visited[nextx][nexty] = index;
                        area++;
                    }
                }
            }
        }
        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));                                  /* 用 visited 记录岛屿是否遍历过 */

        int index = 1;
        bool isAllGrid = true;
        unordered_map<int, int> umap;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                                                   /* 遍历岛屿，记录岛屿数量 */
                if (grid[i][j] == 0) isAllGrid = false;
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    int area = bfs(grid,visited,i,j,index);
                    umap[index] = area;
                    index++;
                }
            }
        }
        if (isAllGrid) return m * n;

        int ret = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                                                   /* 遍历岛屿，记录岛屿数量 */
                int area = 1;
                unordered_set<int> uset;
                if (grid[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int nextx = i + dir[k][0];
                        int nexty = j + dir[k][1];
                        if (nextx < grid.size() && nextx >= 0 &&
                            nexty < grid[0].size() && nexty >= 0) {
                            if (visited[nextx][nexty] != 0 && uset.find(visited[nextx][nexty]) == uset.end()){
                                area += umap[visited[nextx][nexty]];
                                uset.insert(visited[nextx][nexty]);
                            }
                        }
                    }
                }
                ret = max(ret, area);
            }
        }
        
        return ret;
    }
};