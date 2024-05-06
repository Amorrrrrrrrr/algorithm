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

/* ǰ����� */
class Solution {
public:
    int result;
    void travel(TreeNode* cur) {
        if (cur == NULL) return;                                                        /* �����սڵ����ֹ */

        travel(cur->left);
        travel(cur->right);

        if (cur->left != NULL && cur->left->left == NULL && cur->left->right == NULL) { /* ������Ҷ�ӵĸ��ڵ���ռ���� */
            result += cur->left->val;
            return;
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        result = 0;
        travel(root);
        return result;
    }
};