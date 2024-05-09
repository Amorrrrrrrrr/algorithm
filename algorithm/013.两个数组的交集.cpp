#include <unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> tmp(nums1.begin(), nums1.end());             /* 容器、迭代器和算法之间的关系 */
        for(int i = 0; i < nums2.size(); ++i) {
            if (tmp.find(nums2[i]) != tmp.end()) {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};