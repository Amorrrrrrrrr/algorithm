/* ��ȷ��һ��ά�ȣ���ȷ����һ��ά�� */
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {           
        if (a[0] == b[0]) return a[1] < b[1];                           /* ��Ҫ���� */
        return a[0] > b[0];                                             /* ��Ҫ���� */
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result;                                     /* ����ԭ���޸ģ�������� */
        for (int i = 0; i < people.size(); i++) {
            result.insert(result.begin() + people[i][1], people[i]);    /* ̰�Ĳ���(����Ԫ��ǰ�������Ԫ�ض�������(>=)) */
        }
        return result;
    }
};


/* �����Ż� vector */