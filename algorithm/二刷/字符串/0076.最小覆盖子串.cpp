/* �������� + ��ϣ�� */
class Solution {
public:
    bool isBaohan(const vector<int>& s, const vector<int>& t) { /* �����ڴ����� */
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < t[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> tVec(128, 0);
        vector<int> sVec(128, 0);
        for (int i = 0; i < t.size(); i++) {
            tVec[t[i]]++;
        }
        string ret;

        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            sVec[s[fast]]++;

            while (fast - slow + 1 >= t.size() && isBaohan(sVec, tVec)) {
                if (ret.size() != 0 && ret.size() <= fast - slow + 1) {}
                else ret = s.substr(slow, fast - slow + 1);                 /* ԭ���ַ����ָ�̫����� */

                sVec[s[slow]]--;
                slow++;
            }

        }
        return ret;
    }
};


class Solution {
public:

    string minWindow(string s, string t) {
        int tVec[128] = { 0 };
        int sVec[128] = { 0 };

        for (int i = 0; i < t.size(); i++) {
            tVec[t[i]]++;
        }
        string ret;

        int slow = 0;
        int len = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (tVec[s[fast]] > sVec[s[fast]]) {                            /* ֻ�� t �Ĺ�ϣ�� > s �Ĺ�ϣ��ʱ�� len++ */
                len++;
            }
            sVec[s[fast]]++;

            while (len == t.size()) {
                sVec[s[slow]]--;
                if (tVec[s[slow]] > sVec[s[slow]]) {                        /* ֻ�� t �Ĺ�ϣ�� > s �Ĺ�ϣ��ʱ�ż�¼��� */
                    if (ret.empty() || ret.size() > fast - slow + 1) {      /* ��¼��� */
                        ret = s.substr(slow, fast - slow + 1);
                    }

                    len--;
                }
                slow++;
            }
        }
        return ret;
    }
};