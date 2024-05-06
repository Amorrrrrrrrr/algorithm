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
                                                                    /* 终止条件：没有找到/找到 删除节点 + 删除节点 */
                                                                    /* 分析五种情况：
                                                                    * 1.没找到删除节点
                                                                    * 2.删除节点为叶子节点（左空右空）
                                                                    * 3.左不空右空
                                                                    * 4.左空右不空
                                                                    * 5.左不空右不空
                                                                    */
        if (root == NULL) return NULL;
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL)
                return NULL;
            else if (root->left != NULL && root->right == NULL)
                return root->left;                                  /* 直接返回当前结点的左/右子树给上一层（父节点） */
            else if (root->left == NULL && root->right != NULL)
                return root->right;
            else {
                TreeNode* cur = root->right;                        /* 左右均不为空的复杂情况 */
                while (cur->left) { cur = cur->left; }
                cur->left = root->left;
                return root->right;
            }
        }

        if (root->val > key) root->left = deleteNode(root->left, key);  /* 返回根节点的方式 */
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};