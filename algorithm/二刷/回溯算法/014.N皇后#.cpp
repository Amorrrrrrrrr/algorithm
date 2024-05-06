/* 不同集合的组合 */
class Solution {
public:
    bool isValid(vector<string>& board, int x, int y) {
        for (int i = 0; i < x; i++) {
            if (board[i][y] == 'Q') return false;
        }

        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = x, j = y; j < board.size() && i >= 0; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    vector<vector<string>> result;
    void backtracking(vector<string>& board, int x) {
        if (x == board.size()) {
            result.push_back(board);
            return;
        }

        for (int j = 0; j < board.size(); j++) {
            if (!isValid(board, x, j)) continue;

            board[x][j] = 'Q';
            backtracking(board, x + 1);
            board[x][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtracking(board, 0);
        return result;
    }
};