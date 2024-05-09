/* 非排序 + 去重 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int> nums, int startIndex) {
        if (path.size() >= 2) result.push_back(path);

        if (startIndex == nums.size()) return;

        unordered_set<int> uset;                                                        /* 本层递归去重（树层去重）(每层递归/每个结点重新定义新的 uset) */
                                                                                        /* used 数组记录 path 里面用过了哪些元素，非排序不适用 */
                                                                                        /* uset 仅仅负责本层递归里面取过了哪些元素，和 path 没有关系 */
        for (int i = startIndex; i < nums.size(); i++) {
            if (!path.empty() && path[path.size() - 1] > nums[i] || uset.find(nums[i]) != uset.end()) continue; /* 去重 + 非递减条件判断 */
            
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracking(nums, 0);
        return result;
    }
};