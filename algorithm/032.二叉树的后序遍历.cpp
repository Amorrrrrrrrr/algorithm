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
        travel(cur->right, ret);
        ret.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        travel(root, ret);
        return ret;
    }
};

/* 迭代法 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {         /* 栈 + 中右左 + 结果容器 + 反转 */
        vector<int> ret;
        if (root == NULL) return ret;
    
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            ret.push_back(cur->val);
            st.pop();
            if (cur->left) {
                st.push(cur->left);
            }
            if (cur->right) {
                st.push(cur->right);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};