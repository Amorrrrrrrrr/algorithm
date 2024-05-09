/* 模拟转圈：循环不变量原则 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
       //初始化返回的结果数组的大小
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //初始化返回结果数组ans
    int** ans = (int**)malloc(sizeof(int*) * n);
    int i;
    for(i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    int startx = 0, starty = 0;
    int j;
    int offset = 1;
    int num = 1;
    int k;
    for (k = 0; k < n/2; ++k) {
        for (j = starty; j < n - offset; ++j) {
            ans[startx][j] = num++;                         /* 注意：一次转圈后 i 回到 0 导致覆写问题 */
        }
        for (i = startx; i < n - offset; ++i) {
            ans[i][j] = num++;
        }
        for (; j > starty; --j) {
            ans[i][j] = num++;
        }
        for (; i > startx; --i) {
            ans[i][j] = num++;
        }
        startx++;
        starty++;
        offset ++;
    }
    if (n % 2 == 1) {
        ans[startx][starty] = num;
    }
    return ans;
}