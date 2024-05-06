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
    vector<string> res;
    void travel(TreeNode* cur, vector<int>& path) {             /* ����ʱ path ���봫���ã�path ��ֵ���û��� */
        path.push_back(cur->val);                               /* ��Ϊ������Ҷ�ӽڵ㣬�����ȴ����е��߼� */

        if (cur->left == NULL && cur->right == NULL) {          /* ·��������Ҷ�ӽڵ� */
            string str;
            str += to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                str += "->";
                str += to_string(path[i]);
            }
            res.push_back(str);
            return;
        }

        if (cur->left) {
            travel(cur->left, path);
            path.pop_back();
        }

        if (cur->right) {
            travel(cur->right, path);
            path.pop_back();
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return {};
        res.clear();
        vector<int> path;
        travel(root, path);
        return res;
    }
};