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

/* ������� */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL)) return 0;                           /* ����Ҷ�ӽڵ㣬Ҳ return 0���Ե�ǰ�ڵ�Ϊ�������ͳ�ƵĶ���������Ҷ����֮�� */
                                                                                            /* ���ڵ�ſ�ʼ�ռ���Ҷ����֮�� */

        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);

        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {  /* ���ڵ��ռ���Ҷ����֮�� */
            return root->left->val + right;
        }
        return left + right;
    }
};