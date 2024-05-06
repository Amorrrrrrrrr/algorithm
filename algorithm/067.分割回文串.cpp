/* �ָ���Ĵ��������Ƿָ������� */

class Solution {
public:
    bool isPal(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] == s[right]) {
                left++; right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> result;
    vector<string> path;
    void backTracking(const string& s, int startIndex) {                    /* startIndex ����������ϣ����ұ�ʾ�ָ�� */
        if (startIndex == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {                       /* [0, size() - 1] �ָ�������� */
            if (!isPal(s, startIndex, i)) continue;                         /* s[startIndex, i] �Ƿָ���Ӵ�*/

            path.push_back(s.substr(startIndex, i - startIndex + 1));
            backTracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return result;
    }
};