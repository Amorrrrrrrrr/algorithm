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
class Solution {
public:
    void travel(TreeNode* cur, vector<int>& path, vector<string>& result) {     /* ���������Ҫ������ */
        path.push_back(cur->val);                                               /* �У���Ϊ��ֹ������Ҷ�ӽڵ� */

        if (cur->left == NULL && cur->right == NULL) {                          /* ��ֹ������Ҷ�ӽڵ㣺��Ϊ��Ҫ���� */
            string ret;
            for (int i = 0; i < path.size() - 1; i++) {
                ret += to_string(path[i]);
                ret += "->";
            }
            ret += to_string(path[path.size() - 1]);
            result.push_back(ret);
            return;
        }

        if (cur->left) {
            travel(cur->left, path, result);
            path.pop_back();                                                    /* ���� */
        }
        if (cur->right) {
            travel(cur->right, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        travel(root, path, result);
        return result;
    }
};