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

/* ǰ�����(�����������Ҫ����ǰ�����) */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {                                                /* ��ֹ����Ϊ�սڵ��Ҷ�ӽڵ� */
            return NULL;
        }

        TreeNode* cur = new TreeNode(postorder[postorder.size() - 1]);               /* �У�
                                                                                     * 1���������鹹����ڵ� 
                                                                                     * 2�����������Ҹ��ڵ��±� 
                                                                                     * 3���ָ��������� 
                                                                                     * 4���ָ�������� 
                                                                                     */
        if (postorder.size() == 1) {
            return cur;
        }

        int index;
        for (index = 0; index < inorder.size(); index++) {
            if (inorder[index] == cur->val) {
                break;
            }
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end() - 1);

        cur->left = buildTree(leftInorder, leftPostorder);                          /* ���������� */
        cur->right = buildTree(rightInorder, rightPostorder);                       /* ���������� */
        return cur;                                                                 /* ���ع���õĶ����� */
    }
};