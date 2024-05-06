/* 不同集合的组合 */
class Solution {
public:

    bool isValid(vector<vector<char>>& board, int x, int y, char k) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][y] == k) return false;
        }

        for (int j = 0; j < board.size(); j++) {
            if (board[x][j] == k) return false;
        }

        int startRow = (x / 3) * 3;
        int startCol = (y / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == k) return false;
            }
        }

        return true;
    }

    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') continue;
                for (char k = '1'; k <= '9'; k++) {
                    if (!isValid(board, i, j, k)) continue;
                    board[i][j] = k;
                    if(backtracking(board)) return true;        /* 找到结果立刻返回避免超时 */
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};