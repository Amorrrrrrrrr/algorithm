class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int size = 1;
        for (int k = 0; k < n / 2; k++) {
            int startX = k;
            int startY = k;
            int i = startY;                             /* j 负责行(x)，i 负责列(y) */
            int j = startX;
            for (; j < n - startX - 1; j++) {
                result[startX][j] = size;
                size++;
            }
            for (; i < n - startY - 1; i++) {
                result[i][j] = size;
                size++;
            }
            for (; j > startX; j--) {
                result[i][j] = size;
                size++;
            }
            for (; i > startY; i--) {
                result[i][j] = size;
                size++;
            }

        }

        if (n % 2 == 1) result[n / 2][n / 2] = size;

        return result;
    }
};