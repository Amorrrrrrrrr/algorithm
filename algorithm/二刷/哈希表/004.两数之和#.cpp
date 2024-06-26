class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(target - nums[i]) == umap.end()) {
                umap.insert(pair<int, int>(nums[i], i));
            }
            else {
                return vector<int>{umap[target - nums[i]], i};
            }
        }
        return {};
    }
};