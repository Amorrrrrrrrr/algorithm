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
            que.push(que.front());                  /* ѹ�벢���� size - 1 ��Ԫ�� */
            que.pop();

        }
        int result = que.front();                   /* �������������һ��Ԫ�� */
        que.pop();
        return result;
    }

    int top() {
        return que.back();                          /* ���ض������һ��Ԫ�� */
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