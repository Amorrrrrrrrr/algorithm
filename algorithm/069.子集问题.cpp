/* 组合和分割问题都是在叶子节点（终止条件）收集结果，子集问题要去每一个节点都收集结果 */
/* 就不是在终止条件，而是在每一层递归都要把当前本层递归里边的结果放进结果集里 */

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int> nums, int startIndex) {
        result.push_back(path);                                 /* 收集结果在终止条件前面，防止叶子节点的结果没有收集 */

        if (startIndex == nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backTracking(nums, 0);
        return result;
    }
};