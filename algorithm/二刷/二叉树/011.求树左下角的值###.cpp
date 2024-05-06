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

/* ��������������� */
class Solution {
public:
    int maxDepth = INT_MIN;
    TreeNode* res = NULL;
    void travel(TreeNode* cur, int depth) {                 /* �����Ϣ */
        if (cur->left == NULL && cur->right == NULL) {      /* ������Ҷ�ӽڵ� */
            if (depth > maxDepth) {                         /* �ռ���� */
                maxDepth = depth;
                res = cur;
            }
            return;
        }

        if (cur->left) travel(cur->left, depth + 1);
        if (cur->right) travel(cur->right, depth + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        travel(root, 1);
        return res->val;
    }
};