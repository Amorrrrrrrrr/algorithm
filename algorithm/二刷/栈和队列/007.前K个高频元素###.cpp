class Solution {
public:
    class mycompare {
    public:
        bool operator() (pair<int, int> p1, pair<int, int> p2) {                            /* Ð¡¶¥¶Ñ */
            return p1.second > p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pri_que;

        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};