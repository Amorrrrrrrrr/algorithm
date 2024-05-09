class Solution {
    static const int N = 1010;
    int father[N];

    void init() {
        for (int i = 0; i < N; ++i) {
            father[i] = i;
        }
    }

    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    bool isTree(vector<vector<int>>& edges, int index) {                /* 判断删除一条边后是否是树 */
        init();
        for (int i = 0; i < edges.size(); i++) {
            if (i == index) continue;

            if (isSame(edges[i][0], edges[i][1])) return false;
            else join(edges[i][0], edges[i][1]);
        }
        return true;
    }


public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int inDegree[N] = {0};                                          /* 记录和统计节点入度情况 */
        for(int i = 0; i < edges.size(); i++) {
            inDegree[edges[i][1]]++;
        }
        vector<int> vec;                                                /* 记录入度为2的节点的入度边（如果有的话就两条边） */
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (inDegree[edges[i][1]] == 2) {
                vec.push_back(i);
            }
        }

        if (!vec.empty()) {                                             /* 情况1：如果有入度为2的节点，那么一定是两条边里删一个，看删哪个可以构成树 */
            if (isTree(edges, vec[0])) return edges[vec[0]];
            return edges[vec[1]];
        } else {                                                        /* 情况2：明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了 */
            init();
            for (int i = 0; i < edges.size(); i++) {
                if (isSame(edges[i][0], edges[i][1])) return edges[i];
                else join(edges[i][0], edges[i][1]);
            }
        }
        return {};

    }
};