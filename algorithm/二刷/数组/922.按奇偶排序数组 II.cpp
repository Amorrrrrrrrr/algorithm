/* Ë«Ö¸Õë */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ret = vector<int>(nums.size(), 0);
        int one = 0;
        int two = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                while (nums[two] % 2 != 0) two++;

                ret[i] = nums[two];
                two++;
            }
            else {
                while (nums[one] % 2 != 1) one++;

                ret[i] = nums[one];
                one++;
            }
        }
        return ret;
    }
};