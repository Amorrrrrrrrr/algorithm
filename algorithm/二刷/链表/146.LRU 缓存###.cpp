class LRUCache {
public:
    queue<int>q;
    unordered_map<int, int>mp, cnt;
    int size;
    void update(int key) {
        q.push(key);
        cnt[key]++;
        while (mp.size() > size) {
            int x = q.front();
            q.pop();
            cnt[x]--;
            if (!cnt[x]) {
                mp.erase(x);
                cnt.erase(x);
            }
        }
    }
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (mp.count(key)) {
            update(key);
            return mp[key];
        }
        else return -1;
    }

    void put(int key, int value) {
        mp[key] = value;
        update(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */