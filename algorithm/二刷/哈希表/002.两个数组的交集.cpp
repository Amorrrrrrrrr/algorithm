class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset;
        for (int i = 0; i < nums1.size(); i++) {
            uset.insert(nums1[i]);
        }

        vector<int> result;
        for (int j = 0; j < nums2.size(); j++) {
            if (uset.find(nums2[j]) != uset.end()) {
                result.push_back(nums2[j]);
                uset.erase(nums2[j]);
            }
        }
        return result;
    }
};