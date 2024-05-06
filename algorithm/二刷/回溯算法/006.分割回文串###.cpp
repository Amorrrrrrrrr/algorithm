class Solution {
public:
    bool isValid(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }

    vector<vector<string>> result;
    vector<string> path;
    void backTracking(const string& s, int index) {
        if (index == s.size()) {                            /* ��ֹ����ȡ���� index */
            result.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (!isValid(s, index, i)) continue;            
            path.push_back(s.substr(index, i - index + 1)); /* substr(��ʼ�±꣬����) */
            backTracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return result;
    }
};