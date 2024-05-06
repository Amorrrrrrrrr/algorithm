// 先遍历物品，再遍历背包(组合数)
for (int i = 0; i < weight.size(); i++) {                       // 遍历物品
    for (int j = weight[i]; j <= bagWeight; j++) {              // 遍历背包容量(正序)
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}

// 先遍历背包，再遍历物品(排列数)
for (int j = 0; j <= bagWeight; j++) {                          // 遍历背包容量(正序)
    for (int i = 0; i < weight.size(); i++) {                   // 遍历物品
        if (j - weight[i] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) 
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}