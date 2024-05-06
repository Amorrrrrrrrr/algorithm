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

/* 前序遍历(构造二叉树都要用用前序遍历) */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {                                                /* 终止条件为空节点和叶子节点 */
            return NULL;
        }

        TreeNode* cur = new TreeNode(postorder[postorder.size() - 1]);               /* 中：
                                                                                     * 1、后序数组构造根节点 
                                                                                     * 2、中序数组找根节点下标 
                                                                                     * 3、分割中序数组 
                                                                                     * 4、分割后序数组 
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

        cur->left = buildTree(leftInorder, leftPostorder);                          /* 构造左子树 */
        cur->right = buildTree(rightInorder, rightPostorder);                       /* 构造右子树 */
        return cur;                                                                 /* 返回构造好的二叉树 */
    }
};