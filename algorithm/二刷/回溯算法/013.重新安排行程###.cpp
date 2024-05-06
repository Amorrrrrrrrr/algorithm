/* 超出时间限制 */
class Solution {
public:
    vector<string> result;
    vector<string> path;
    void backtracking(vector<vector<string>>& tickets, string cur, vector<bool>& used) {  /* 使用 used 数组记录使用过的元素 */
        if (path.size() == tickets.size() + 1) {
            if (result.empty()) result = path;

            for (int i = 0; i < path.size(); i++) {
                if (path[i].compare(result[i]) > 0) break;
                if (path[i].compare(result[i]) < 0) {
                    result = path;
                    break;
                }
            }

            return;
        }

        for (int i = 0; i < tickets.size(); i++) {
            if (used[i] == true) continue;
            if (tickets[i][0] != cur) continue;

            path.push_back(tickets[i][1]);
            used[i] = true;
            backtracking(tickets, tickets[i][1], used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(), false);
        result.clear();
        path.clear();
        path.push_back("JFK");
        backtracking(tickets, "JFK", used);
        return result;
    }
};