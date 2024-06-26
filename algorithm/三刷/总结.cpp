一. 数组
    1. 螺旋矩阵注意边界

二. 链表
    1. 移除链表中的元素：终止条件为 while(cur->next);
    2. 设计链表：注意判断节点是否存在。

三.哈希表
    1. 四数之和：注意(long long)nums[i] + nums[j] + nums[left] + nums[right] > target

四.字符串
    1. 反转字符串II
    2. 反转字符串中的单词：去掉字符串中的空格时注意末尾的空格
    3. 手撕 KMP 算法
    4. 字符串中查找字符串：t.find(s) != std::string::npos
    5. 重复的子字符串：只比较 next 数组的最后一位

五.回溯
    1. 电话号码的字母组合（多个集合的组合）
    2. 组合总和II：树层去重（next[i - 1] == false -> continue)
    3. 复原 IP 地址(经典分割问题)
    4. 子集和组合去重只能使用：排序(sort)###  + next数组 / uset哈希表->uset 树层去重不用 erase 元素
    5. 非递减子序列(子集问题，但自动排序)->子集与组合的区别：子集收集结果但不 return
    6. 综合问题三大件

六：动态规划
    1. 整数拆分
    7. 摆动序列：第 j 个山谷 + 1 = 第 i 个山峰
    2. 01背包问题：int j = backage; j >= nums[i]; j--
        （1）一定容量的背包最多能装多少价值的物品
        （2）一定容量的背包最多能装多少价值的物品（背包和物品含有两种属性）（例：一和零）
        （3）装满一定容量的背包一共有多少种方法（例：目标和）
    3. 完全背包问题：int j = nums[i]; j <= backage; j++
        （1） 求组合数
        （2） 求排列数：注意边界（背包 > 物品 && 背包不能溢出）
        （3） 装满一定容量的背包最少需要多少件物品（例：零钱兑换）
        （4） 单词拆分（排列数 + 递推公式）
    4. 打家劫舍问题：一维数组即可解决
    5. 股票问题
    6. 子序列与子数组问题：以 i 为尾的子序列 / 子数组的长度
        （1） 最长递增
        （2） 最长重复
        （3） 最大子数组和
(###)   （5） 回文子串和回文子序列
        （4） 编辑距离问题（最长公共子序列问题）
            I : 判断子序列
            II：不同的子序列（重复最长公共子序列）
            III：两个字符串的删除操作
            IV：编辑距离

七：图论
    1. 深度优先搜索：回溯模板（index）
    2. 广度优先搜索：队列实现
        （1） 岛屿问题：队列中加入一个元素 visited 变为 true
            I：飞地的数量：if(grid[i][0] == 1 && visited[i][0] == false)
        （2） 层序遍历：记录每一层的元素个数
            I：单词接龙
    3. 钥匙和房间：记录访问过的房间

八：并查集
    1. 冗余连接II：inDigit 的大小 != edges.size();

九：贪心算法
    1. 分发饼干：胃口和饼干一起考虑（双指针）
    2. 跳跃游戏II： for (int i = 0; i <= range; i++) + if (range >= nums.size() - 1) return ret;
    3. 区间问题
        （1） 重复区间
        （2） 划分字母区间：for (int i = 0; i < s.size(); i++) + 双指针






