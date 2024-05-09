class Solution {
    int n = 200005;
    vector<int> father = vector<int>(n, 0);
    void init() {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    void join(int u, int v) {
        u = find(u);                                                                /* 是 find 不是 father */
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init();
        for (int i = 0; i < edges.size(); i++) {
            join(edges[i][0], edges[i][1]);
        }
        return isSame(source, destination);
    }
};