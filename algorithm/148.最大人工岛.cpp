/* 深度优先搜索 */
class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int count = 0;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark) {
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            if (visited[nextx][nexty] == false && grid[nextx][nexty] == 1) {
                grid[nextx][nexty] = mark;                                                                           /* 更新每个岛屿的编号和面积 */
                count++;
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty, mark);
            }
        }
    }

/* 第一步：一次遍历地图，得出各个岛屿的面积，并做编号记录。可以使用 map 记录，key 为岛屿编号，value 为岛屿面积 
 * 第二步：在遍历地图，遍历0的方格（因为要将0变成1），并统计该1（由0变成的1）周边岛屿面积，将其相邻面积相加在一起，遍历所有 0 之后，就可以得出 选一个0变成1之后的最大面积。
 */
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_map<int, int> umap;

        int mark = 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && grid[i][j] == 1) {
                    grid[i][j] = mark;
                    count = 1;
                    visited[i][j] = true;
                    dfs(grid, visited, i, j, mark);
                    umap[mark] = count;                                                                                 /* 记录每个岛屿的编号和面积 */
                    mark++;
                }
            }
        }

        int result = 0;
        int isAll = true;                                                                                               /* 特殊情况：全是陆地 */
        unordered_set<int> visitedGrid;                                                                                 /* 标记访问过的岛屿 */ 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visitedGrid.clear(); 
                if (grid[i][j] == 0) {
                    isAll = false;
                    int area = 1;                                                                                       /* 当前遍历的 0 记录在面积中 */
                    for (int k = 0; k < 4; k++) {
                        int nextx = i + dir[k][0];
                        int nexty = j + dir[k][1];
                        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
                        if (grid[nextx][nexty] != 0 && visitedGrid.find(grid[nextx][nexty]) == visitedGrid.end()) {     /* 访问过的岛屿不再访问 */ 
                            area += umap[grid[nextx][nexty]];
                            visitedGrid.insert(grid[nextx][nexty]);
                        }
                    }
                    result = max(result, area);
                }
            }
        }
        if (isAll) return m * n;

        return result;
    }
};