class Solution {
public:
    int n = 1005;
    vector<int> father = vector<int>(n, 0);
    void init() {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for (int i = 0; i < edges.size(); i++) {
            if (isSame(edges[i][0], edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }
};