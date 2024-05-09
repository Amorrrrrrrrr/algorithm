/* 广度优先搜索 */
class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dsp(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
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
                if (visited[nextx][nexty] == false && grid[nextx][nexty] == 'O') {
                    que.push({nextx, nexty});
                    visited[nextx][nexty] = true;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            if (visited[i][0] == false && board[i][0] == 'O') {
                dsp(board, visited, i, 0);
            }
            if (visited[i][n - 1] == false && board[i][n - 1] == 'O') {
                dsp(board, visited, i, n - 1);
            }
        }
        for (int j = 0; j < n; j++) {
            if (visited[0][j] == false && board[0][j] == 'O') {
                dsp(board, visited, 0, j);
            }
            if (visited[m - 1][j] == false && board[m - 1][j] == 'O') {
                dsp(board, visited, m - 1, j);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

};