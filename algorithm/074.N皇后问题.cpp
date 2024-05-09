/* 不同集合间的组合，类似于电话号码的组合 */

class Solution {
public:
    bool isValid(vector<string> chessBoard, int n, int row, int i) {
        for (int j = 0; j < row; j++) {                                 /* 行剪枝 */
            //if (chessBoard[row][j] == 'Q') return false;              /* 同行不用检查（因为在单层搜索的过程中，每一层递归，只会选for循环（也就是同一行）里的一个元素） */
            if (chessBoard[j][i] == 'Q') return false;
        }
        int k = row;
        int l = i;
        while (row >= 0 && i >= 0) {
            if (chessBoard[row][i] == 'Q') return false;
            row--;
            i--;  
        }
        // row = k; i = l;
        // while (row < n && i < n) {                                   /* 向下不用检查 */
        //     if (chessBoard[row][i] == 'Q') return false;
        //     row++;
        //     i++;  
        // }
        // row = k; i = l;
        // while (row < n && i >= 0) {
        //     if (chessBoard[row][i] == 'Q') return false;
        //     row++;
        //     i--;  
        // }
        row = k; i = l;
        while (row >= 0 && i < n) {
            if (chessBoard[row][i] == 'Q') return false;
            row--;
            i++;  
        }
        return true;
    }

    vector<vector<string>> result;
    void backTracking(vector<string> chessBoard, int n, int row) {  /* 在二维数组上直接修改结果，行数是递归深度 */
        if (row == n) {
            result.push_back(chessBoard);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!isValid(chessBoard, n, row, i)) continue;          /* 合法性判断 */

            chessBoard[row][i] = 'Q';
            backTracking(chessBoard, n, row + 1);
            chessBoard[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessBoard(n, string(n, '.'));
        backTracking(chessBoard, n, 0);
        return result;
    }
};