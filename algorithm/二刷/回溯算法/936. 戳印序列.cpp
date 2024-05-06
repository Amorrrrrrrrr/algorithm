/* 超出时间限制 */
class Solution {
public:

    vector<int> path;
    bool backTracking(string str, string stamp, string target, vector<bool>& used) {
        if (str == target && path.size() <= 10 * target.size()) return true;

        for (int i = 0; i <= target.size() - stamp.size(); i++) {
            if (used[i] == true) continue;
            string tmp = str;
            for (int j = 0; j < stamp.size(); j++) {
                str[i + j] = stamp[j];
            }
            path.push_back(i);
            used[i] = true;
            if (backTracking(str, stamp, target, used)) return true;
            str = tmp;
            path.pop_back();
            used[i] = false;
        }
        return false;
    }

    vector<int> movesToStamp(string stamp, string target) {
        string str(target.size(), '?');
        vector<bool> used(target.size() - stamp.size() + 1, false);
        if (!backTracking(str, stamp, target, used)) return {};

        return path;
    }
};