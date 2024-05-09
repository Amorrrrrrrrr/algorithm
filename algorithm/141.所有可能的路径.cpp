/* 有向图路径问题，最合适使用深搜 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void dsp(vector<vector<int>>& graph, int index) {
        if (index == graph.size() - 1) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < graph[index].size(); i++) {
            path.push_back(graph[index][i]);
            dsp(graph, graph[index][i]);
            path.pop_back();
        }
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        result.clear();path.clear();
        path.push_back(0);                                  // 无论什么路径已经是从0节点出发
        dsp(graph, 0);
        return result;
    }
};