/* 深搜模板 */
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int index) {
        if (graph.size() - 1 == path.back()) {
            ret.push_back(path);
            return;
        }
        if (graph[index].size() == 0) {
            return;
        }

        for (int i = 0; i < graph[index].size(); i++) {
            path.push_back(graph[index][i]);
            dfs(graph, graph[index][i]);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (graph.size() == 0) return {};

        path.push_back(0);
        dfs(graph, 0);
        return ret;
    }
};