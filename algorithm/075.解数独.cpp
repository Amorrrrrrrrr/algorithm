class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int column, char k) {        /* 有效值判断 */
        for (int i = 0; i < 9; i++) {                                               /* 行的所有元素都需要判断 */
            if (board[i][column] == k) return false;                                
        }
    
        for (int j = 0; j < 9; j++) {                                               /* 列的所有元素都需要判断 */
            if (board[row][j] == k) return false;
        }

        int startRow = row - row % 3;                                               /* 计算写在循环外，避免重复计算，避免超时 */
        int startCol = column - column % 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == k) return false;
            }
        }

        return true;
    }

    bool backTracing(vector<vector<char>>& board) {                                 /* 递归深度：空的数量；board 直接原地修改结果；返回类型 bool：找到单个结果立刻就返回 */

                                                                                    /* 终止条件在下面的处理逻辑中就给包含了 */

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') continue;
                
                for (char k = '1'; k <= '9'; k++) {
                    if (!isValid(board, i, j, k)) continue;
                    board[i][j] = k;
                    bool result = backTracing(board);
                    if (result == true) return true;
                    board[i][j] = '.';
                }
                return false;                                                       /* return false 走回溯的过程后再走下一条路。*/
            }
        }
        return true;                                                                /* return true 直接返回 */
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backTracing(board);
    }
};