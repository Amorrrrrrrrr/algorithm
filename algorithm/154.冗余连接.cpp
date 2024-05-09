class Solution {
    int n = 1005;
    vector<int> father = vector<int>(n , 0);
    void init() {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

public:
/* 如果边的两个节点已经出现在同一个集合里，说明着边的两个节点已经连在一起了，再加入这条边一定就出现环了。 */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        vector<int> result;
        for (int i = 0; i < edges.size(); i++) {                        /* 优化：从后向前遍历 + return edges[i]; */
            if (isSame(edges[i][0], edges[i][1])) {                     /* 如果题目中说：如果有多个答案，则返回二维数组中最前出现的边。那我们就要直接 return edges[i]; */
                result = {edges[i][0], edges[i][1]};                    /* 记录多余连接 */
            }
            else {
                join(edges[i][0], edges[i][1]);
            }
        }
        return result;
    }
};