/* �������� */
class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        dq.push_back(t);
        while (!dq.empty() && dq.front() < t - 3000) {
            dq.pop_front();
        }
        return dq.size();
    }

    deque<int> dq;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */