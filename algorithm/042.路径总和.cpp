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

 /* �ݹ�+����(��ֵ��ʽ) */
class Solution {
public:
    bool travel(TreeNode* cur, int targetSum) {                             /* ����ֵ����ֻҪĳһ��·�����Ͼ����̷��أ����������н�� */   /* targetSum��Ŀ��ֵ */
        if (cur->left == NULL && cur->right == NULL && targetSum == 0) {    /* ��ֹ�����Ǹ��ڵ�ĸ������ */
            return true;
        }
        if (cur->left == NULL && cur->right == NULL && targetSum != 0) {
            return false;
        }
        if (cur->left) {
            targetSum -= cur->left->val;
            if (travel(cur->left, targetSum)) return true;                  /* �ǵ��з���ֵ���ҵ�����������·�������̷��أ� */
            targetSum += cur->left->val;
        }
        if (cur->right) {
            targetSum -= cur->right->val;
            if (travel(cur->right, targetSum)) return true;
            targetSum += cur->right->val;
        }
        return false;                                                       /* �ǵ��з���ֵ */
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return travel(root, targetSum - root->val);                         /* ��ֵ��ʽ���ݵĲ��� */
    }
};