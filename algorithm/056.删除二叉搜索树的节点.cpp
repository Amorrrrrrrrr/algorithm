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
    TreeNode* deleteNode(TreeNode* root, int key) {
                                                                    /* ��ֹ������û���ҵ�/�ҵ� ɾ���ڵ� + ɾ���ڵ� */
                                                                    /* �������������
                                                                    * 1.û�ҵ�ɾ���ڵ�
                                                                    * 2.ɾ���ڵ�ΪҶ�ӽڵ㣨����ҿգ�
                                                                    * 3.�󲻿��ҿ�
                                                                    * 4.����Ҳ���
                                                                    * 5.�󲻿��Ҳ���
                                                                    */
        if (root == NULL) return NULL;
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL)
                return NULL;
            else if (root->left != NULL && root->right == NULL)
                return root->left;                                  /* ֱ�ӷ��ص�ǰ������/����������һ�㣨���ڵ㣩 */
            else if (root->left == NULL && root->right != NULL)
                return root->right;
            else {
                TreeNode* cur = root->right;                        /* ���Ҿ���Ϊ�յĸ������ */
                while (cur->left) { cur = cur->left; }
                cur->left = root->left;
                return root->right;
            }
        }

        if (root->val > key) root->left = deleteNode(root->left, key);  /* ���ظ��ڵ�ķ�ʽ */
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};