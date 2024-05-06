/* »¬¶¯´°¿Ú */
class Solution {

public:

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset;
        if (k > nums.size()) k = nums.size();
        for (int i = 0; i < k; i++) {
            if (uset.find(nums[i]) != uset.end()) return true;
            uset.insert(nums[i]);
        }

        for (int i = k; i < nums.size(); i++) {
            if (uset.find(nums[i]) != uset.end()) return true;
            uset.insert(nums[i]);
            uset.erase(nums[i - k]);
        }

        return false;
    }
};