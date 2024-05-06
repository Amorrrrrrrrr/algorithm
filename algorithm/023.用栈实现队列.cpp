class MyQueue {
public:
    stack<int> stackin;                                         /* 成员变量 */
    stack<int> stackout;

    MyQueue() {

    }

    void push(int x) {
        stackin.push(x);
    }

    int pop() {
        if (stackout.empty()) {
            while (!stackin.empty()) {
                stackout.push(stackin.top());                   /* 先取值再弹出 */
                stackin.pop();
            }
        }
        int result = stackout.top();
        stackout.pop();
        return result;
    }

    int peek() {
        int result = this->pop();                               /* 先弹出再压入 */
        stackout.push(result);
        return result;
    }

    bool empty() {
        return stackout.empty() && stackin.empty();
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