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
 * - 确定递归的终止条件
 * - 确定单层搜索（递归）的逻辑
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int k, int target, int sum, int startIndex) {
        if (sum > target) return;                                                   /* 条件剪枝优化 */
        if (path.size() == k) {
            if (sum == target) {
                result.push_back(path);
                return;
            }
            return;
        }

        for (int i = startIndex; i <= 9 + path.size() - k + 1; i++) {               /* 递归广度剪枝优化(本层尚未开始：9 - i + 1 = k - path.size() ) */
            path.push_back(i);
            sum += i;
            backTracking(k, target, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k, n, 0, 1);
        return result;
    }
};