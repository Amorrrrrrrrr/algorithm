/*
 *  优先级队列：底层实现二叉树，堆逻辑，弹出堆顶元素（堆就是完全二叉树，同时保证父节点和子节点的顺序关系）
 *  - 小顶堆：堆顶是最小的元素
 *  - 大顶堆：堆顶是最大的元素
 */



class Solution {
public:
    class mycomparison {                                                                                /* 排序类 */
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {             
            return lhs.second > rhs.second;                                                             /* 小顶堆排序规则 */
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;                                                                    /* 哈希表 */
        for(int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomparison> que;                         /* 小顶堆 */
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {             /* map 容器遍历 */
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }

        vector<int> result;
        result.resize(k);

        for (int i = k - 1; i >= 0; i--) {
            result[i] = que.top().first;
            que.pop();                                                                                  /* 先取值后弹出 */
        }

        return result;
    }
};