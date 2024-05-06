class MyStack {
public:
	queue<int> que;
	MyStack() {

	}

	void push(int x) {
		que.push(x);
	}

	int pop() {
		int size = que.size();
		size--;
		while (size--) {
			que.push(que.front());
			que.pop();
		}

		int ret = que.front();
		que.pop();
		return ret;
	}

	int top() {
		return que.back();
	}

	bool empty() {
		return que.empty();
	}
};