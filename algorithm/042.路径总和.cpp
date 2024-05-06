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

 /* 递归+回溯(传值方式) */
class Solution {
public:
    bool travel(TreeNode* cur, int targetSum) {                             /* 返回值？：只要某一条路径符合就立刻返回，不遍历所有结点 */   /* targetSum：目标值 */
        if (cur->left == NULL && cur->right == NULL && targetSum == 0) {    /* 终止条件是根节点的各种情况 */
            return true;
        }
        if (cur->left == NULL && cur->right == NULL && targetSum != 0) {
            return false;
        }
        if (cur->left) {
            targetSum -= cur->left->val;
            if (travel(cur->left, targetSum)) return true;                  /* 记得有返回值（找到满足条件的路径，立刻返回） */
            targetSum += cur->left->val;
        }
        if (cur->right) {
            targetSum -= cur->right->val;
            if (travel(cur->right, targetSum)) return true;
            targetSum += cur->right->val;
        }
        return false;                                                       /* 记得有返回值 */
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return travel(root, targetSum - root->val);                         /* 传值方式回溯的参数 */
    }
};