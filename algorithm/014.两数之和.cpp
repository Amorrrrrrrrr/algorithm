#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++) {
            int s = target - nums[i];
            if (mymap.find(s) != mymap.end()) {             /* map 容器存放遍历过的元素 */
                return { mymap[s], i };
            }
            else {
                mymap.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};