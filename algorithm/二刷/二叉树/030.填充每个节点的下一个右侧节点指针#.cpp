/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* pre = NULL;
            for(int i = 0; i < size; i++) {
                Node* cur = que.front(); que.pop();
                if (pre != NULL) cur->next = pre;
                pre = cur;

                if (cur->right) que.push(cur->right);   /* 先添加右孩子，再添加左孩子，实现从后向前遍历 */
                if (cur->left) que.push(cur->left);
            }
        }

        return root;
    }
};