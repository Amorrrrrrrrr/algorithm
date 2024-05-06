class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                int tmp = stIn.top(); stIn.pop();
                stOut.push(tmp);
            }
        }

        int ret = stOut.top();
        stOut.pop();
        return ret;
    }

    int peek() {
        int ret = this->pop();                      /* 直接使用已有的pop函数 */
        stOut.push(ret);
        return ret;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */