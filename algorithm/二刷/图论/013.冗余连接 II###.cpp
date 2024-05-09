class Solution {
public:
    static const int N = 1005;
    vector<int> father = vector<int>(N, 0);
    void init() {
        for (int i = 0; i < N; i++) {
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

    bool isTree(vector<vector<int>>& edges, int index) {
        init();
        for (int i = 0; i < edges.size(); i++) {
            if (i == index) continue;

            if (isSame(edges[i][0], edges[i][1])) {
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int inDegree[N] = {0};
        for (int i = 0; i < edges.size(); i++) {
            inDegree[edges[i][1]]++;
        }

        vector<int> vec;
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (inDegree[edges[i][1]] == 2) {
                vec.push_back(i);
            }
        }

        if (vec.size() > 0) {
            for (int i = 0; i < vec.size(); i++) {
                if (isTree(edges, vec[i]))
                    return edges[vec[i]];
            }
        } 
        else {
            init();
            for (int i = 0; i < edges.size(); i++) {
                if (isSame(edges[i][0], edges[i][1])) {
                    return edges[i];
                }
                join(edges[i][0], edges[i][1]);
            }
        }
        return {};
    }
};