/* 优先级队列求中位数（大顶堆+小顶堆） */
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> pri_min;     /* 小顶堆：保存较大值 */
    priority_queue<int, vector<int>, less<int>> pri_max;        /* 大顶堆：保存较小值 */
    MedianFinder() {

    }

    void addNum(int num) {
        if (!pri_min.empty() && num > pri_min.top()) {
            pri_min.push(num);
            if (pri_min.size() > pri_max.size() + 1) {
                pri_max.push(pri_min.top());
                pri_min.pop();
            }
        }
        else {
            pri_max.push(num);
            if (pri_max.size() > pri_min.size() + 1) {
                pri_min.push(pri_max.top());
                pri_max.pop();
            }
        }
    }

    double findMedian() {
        if (pri_min.size() > pri_max.size()) return pri_min.top();
        else if (pri_min.size() < pri_max.size()) return pri_max.top();
        else return ((double)pri_min.top() + pri_max.top()) / 2;
    }
};