/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /* 递归法 */
class Solution {
public:
    void travel(TreeNode* cur, vector<int>& ret) {
        if (cur == NULL) {
            return;
        }

        travel(cur->left, ret);
        ret.push_back(cur->val);
        travel(cur->right, ret);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        travel(root, ret);
        return ret;
    }
};


/* 迭代法 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {          /* 栈 + 指针 + 左中右 + 结果容器 */
        stack<TreeNode*> st;                                /* 栈：保存遍历过的元素 */
        vector<int> result;
        if (root == NULL) return result;
        TreeNode* cur = root;                               /* 指针：正在遍历的元素 */
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top(); st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};