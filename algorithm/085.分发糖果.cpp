/* 两边分别考虑（不要左边和右边一起去比较，特别有这种两边的情况，我们一定是先确定一边，再确定另一边） */
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size(), 1);
        vector<int> right(ratings.size(), 1);
        int result = 0;
        for (int i = 1; i < ratings.size(); i++) {          /* 从左到右考虑 */
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            else {
                left[i] = 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {     /* 从右到左考虑 */
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
            else {
                right[i] = 1;
            }
        }
        for (int i = 0; i < ratings.size(); i++) {          /* 实际情况 */
            result += max(left[i], right[i]);
        }
        return result;
    }
};