#include <unordered_map>

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mymap;
        int count = 0;
        for (auto a : nums1) {
            for (auto b : nums2) {
                mymap[a + b]++;
            }
        }
        for (auto c : nums3) {
            for (auto d : nums4) {
                if (mymap.find(0 - c - d) != mymap.end()) {
                    count += mymap[0 - c - d];
                }
            }
        }
        return count;
    }
};