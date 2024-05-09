/* 二维 dp 数组 */
class Solution {
public:
    void test_2_wei_bag_problem1() {
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagweight = 4;

        vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));                       /* dp[i][j]: 从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少 */


        for (int j = weight[0]; j <= bagweight; j++) {                                              /* 初始化 */
            dp[0][j] = value[0];
        }

        for(int i = 1; i < weight.size(); i++) {    // 遍历物品                                     
            for(int j = 0; j <= bagweight; j++) {   // 遍历背包容量
                                                                                                    /* 遍历顺序可调换 */
                if (j < weight[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);             /* 不放物品 i 和放物品 i */

            }
        }

        cout << dp[weight.size() - 1][bagweight] << endl;
    }

    int main() {
        test_2_wei_bag_problem1();
    }


};

/* 一维 dp 数组 */
class Solution {
public:
    void test_1_wei_bag_problem() {
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagWeight = 4;

        
        vector<int> dp(bagWeight + 1, 0);                                       /* dp[j]: 容量为j的背包所能装的最大价值为 dp[j] */
                                                                                /* 初始化 */
        for(int i = 0; i < weight.size(); i++) {            // 遍历物品
            for(int j = bagWeight; j >= weight[i]; j--) {   // 遍历背包容量(倒序：为了保证物品i只被放入一次) 
                                                                                /* 遍历顺序不可调换 */
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);               /* 不放物品 i 和放物品 i */
            }
        }
        cout << dp[bagWeight] << endl;
    }

    int main() {
        test_1_wei_bag_problem();
    }
};