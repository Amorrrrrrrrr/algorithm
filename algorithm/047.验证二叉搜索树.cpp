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

/* �������������ԣ����������ʱ��Ԫ���ǵ��������� */
class Solution {
public:
    long long preValue = LONG_MIN;              /* ��¼ǰһ������ֵ */
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        if (root->val > preValue) {
            preValue = root->val;
        }
        else return false;
        bool right = isValidBST(root->right);
        return left && right;                   /* �����ҿ������н������ */
    }
};

/* ˫ָ���Ż� */
class Solution {
public:
    TreeNode* pre = NULL;                       /* ��¼ǰһ����� */
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        if (pre != NULL && pre->val >= root->val) {
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};