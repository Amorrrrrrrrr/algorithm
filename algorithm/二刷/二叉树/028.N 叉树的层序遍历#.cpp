/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) return {};
        queue<Node*> que;
        que.push(root);
        vector<vector<int>> result;
        while(!que.empty()) {
            int size = que.size();
            vector<int> path;
            while (size--) {
                Node* cur = que.front();que.pop();
                path.push_back(cur->val);
                if (cur->children.size() != NULL) {
                    for (int i = 0; i < cur->children.size(); i++) {    /* 遍历子节点 */
                        que.push(cur->children[i]);
                    }
                }
            }
            result.push_back(path);
        }
        return result;
    }
};