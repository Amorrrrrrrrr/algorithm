/* 深度优先搜索 */
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) continue;    // 越界了，直接跳过
            if (!visited[nextx][nexty]) {                                                                     // 终止条件写在了循环里面
                if (heights[nextx][nexty] < heights[x][y]) continue;

                visited[nextx][nexty] = true; 
                dfs(heights, visited, nextx, nexty);
            } 
        }
    }

/* 从太平洋边上的节点 逆流而上，将遍历过的节点都标记上。 
 * 从大西洋的边上节点 逆流而长，将遍历过的节点也标记上。 
 * 然后两方都标记过的节点就是既可以流太平洋也可以流大西洋的节点。
 */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {                             
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> lvisited = vector<vector<bool>>(n, vector<bool>(m, false)); 
        vector<vector<bool>> rvisited = vector<vector<bool>>(n, vector<bool>(m, false)); 
        vector<vector<int>> result; 

        for (int i = 0; i < n; i++) {
            lvisited[i][0] = true;
            dfs(heights, lvisited, i, 0);                                                           // 将与其链接的陆地都标记上 true
        }
        for (int j = 0; j < m; j++) {
            lvisited[0][j] = true;
            dfs(heights, lvisited, 0, j);                                                           
        }
        for (int i = 0; i < n; i++) {
            rvisited[i][m - 1] = true;
            dfs(heights, rvisited, i, m - 1);                                                          
        }
        for (int j = 0; j < m; j++) {
            rvisited[n - 1][j] = true;
            dfs(heights, rvisited, n - 1, j);                                                         
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lvisited[i][j] == true && rvisited[i][j] == true) {
                    result.push_back(vector<int>{i, j});
                }
            }
        }


        return result;
    }
};