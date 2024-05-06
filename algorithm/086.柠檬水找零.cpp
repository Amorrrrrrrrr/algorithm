/* 先找大的，再找小的 */
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int my[3] = { 0, 0, 0 };
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 20) {
                if (my[1] >= 1 && my[0] >= 1) {
                    my[1] -= 1;
                    my[0] -= 1;
                    my[2]++;
                }
                else if (my[0] >= 3) {
                    my[0] -= 3;
                    my[2]++;
                }
                else return false;
            }
            else if (bills[i] == 10) {
                    if (my[0] >= 1) {
                        my[0] -= 1;
                        my[1]++;
                    }
                    else return false;
            }
            else if (bills[i] == 5) {
                        my[0]++;
            }
        }
        return true;
    }
};