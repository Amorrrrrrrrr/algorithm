/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 回溯算法就是用递归来控制有多少层for循环，递归里的每一层其实是一个for循环 */

/* 回溯三部曲：
 * - 递归函数的参数和返回值（因为回溯就是靠递归来实现的）
 * - 确定递归的终止条件（递归深度）
 * - 确定单层搜索（递归）的逻辑
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int n, int k, int startIndex) {                   /* 每次递归通过传入一个参数 startIndex 来控制每次搜索的起始位置 */
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) /* 剪枝优化 */
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return result;
    }
};


 /* 回溯算法是纯暴力搜索，优化是做剪枝操作 */
 /* 回溯算法的剪枝套路有哪些？ */