class Solution {
public:

    vector<string> path;
    bool backtracking(unordered_map<string, map<string, int>>& tickets, string cur, int ticketNum) {    /* 返回值 bool 为了只返回一个结果 */

        if (path.size() == ticketNum + 1) return true;                  /* 终止条件（站点数 = 车票数 + 1） */

        for (auto& next : tickets[cur]) {
            if (next.second > 0) {
                path.push_back(next.first);
                next.second--;
                if (backtracking(tickets, next.first, ticketNum)) return true;
                path.pop_back();
                next.second++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        path.clear();
        path.push_back("JFK");

        unordered_map<string, map<string, int>> umap;                   /* 对车票重新排序（始发站，终点站，车票数量） */
        for (int i = 0; i < tickets.size(); i++) {
            umap[tickets[i][0]][tickets[i][1]]++;
        }

        backtracking(umap, "JFK", tickets.size());
        return path;
    }
};