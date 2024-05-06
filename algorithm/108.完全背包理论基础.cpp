// �ȱ�����Ʒ���ٱ�������(�����)
for (int i = 0; i < weight.size(); i++) {                       // ������Ʒ
    for (int j = weight[i]; j <= bagWeight; j++) {              // ������������(����)
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}

// �ȱ����������ٱ�����Ʒ(������)
for (int j = 0; j <= bagWeight; j++) {                          // ������������(����)
    for (int i = 0; i < weight.size(); i++) {                   // ������Ʒ
        if (j - weight[i] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) 
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}