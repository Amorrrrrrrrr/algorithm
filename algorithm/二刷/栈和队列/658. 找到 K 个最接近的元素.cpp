/* »¬¶¯´°¿Ú */
class Solution {
public:
    class mycompare {
    public:
        bool operator() (pair<int, int> p1, pair<int, int> p2) {                            /* Ð¡¶¥¶Ñ */
            if (p1.second == p2.second) return p1.first > p2.first;
            return p1.second > p2.second;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pri_que;
        for (int i = 0; i < arr.size(); i++) {
            pri_que.push(pair<int, int>(arr[i], abs(arr[i] - x)));
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pri_que.top().first);
            pri_que.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};