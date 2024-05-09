/* 岛屿的数量 * 4 - 邻边的数量 \*\/*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int gridNum = 0;
        int cover = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    gridNum++;
                    if (i > 0 && grid[i - 1][j] == 1) cover++;
                    if (i < grid.size() - 1 && grid[i + 1][j] == 1) cover++;
                    if (j > 0 && grid[i][j - 1] == 1) cover++;
                    if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) cover++;
                }
            }
        }
        return gridNum * 4 - cover;
    }
};