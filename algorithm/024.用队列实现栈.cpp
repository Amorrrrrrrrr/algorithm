class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size() - 1;
        while (size--) {
            que.push(que.front());                  /* 压入并弹出 size - 1 个元素 */
            que.pop();

        }
        int result = que.front();                   /* 弹出队列中最后一个元素 */
        que.pop();
        return result;
    }

    int top() {
        return que.back();                          /* 返回队列最后一个元素 */
    }

    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */