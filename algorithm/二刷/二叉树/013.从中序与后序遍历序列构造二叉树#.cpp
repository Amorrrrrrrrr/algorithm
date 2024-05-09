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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        if (inorder.size() == 1) return new TreeNode(inorder[0]);

        int curValue = postorder[postorder.size() - 1];
        TreeNode* cur = new TreeNode(curValue);                                     /* 申请新空间的方式 */

        int index = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == curValue) {
                index = i;
                break;
            }
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + index);
        vector<int> rightPostorder(postorder.begin() + index, postorder.end() - 1);

        cur->left = buildTree(leftInorder, leftPostorder);
        cur->right = buildTree(rightInorder, rightPostorder);

        return cur;
    }
};