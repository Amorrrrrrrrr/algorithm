class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int line = 0;
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ret++;
                    for (int k = 0; k < 4; k++) {
                        int curx = i + dir[k][0];
                        int cury = j + dir[k][1];
                        if (curx >= 0 && curx < m && cury >= 0 && cury < n) {
                            if (grid[curx][cury] == 1) {
                                line++;
                            }
                        }
                    }
                }
                
            }
        }
        return ret * 4 - line;
    }
};