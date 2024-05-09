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

 /* 后序遍历 */
 /* 贪心策略：在叶子结点的父节点放摄像头 */
class Solution {
public:
    int result = 0;
    int travel(TreeNode* cur) {                     /* 返回值表示状态 */
        if (cur == NULL) return 2;                  /* 情况1：空节点为被覆盖状态 */

        int left = travel(cur->left);
        int right = travel(cur->right);

        if (left == 0 || right == 0) {
            result++;
            return 1;                               /* 监控状态 */
        } else if (left == 1 || right == 1) {
            return 2;                                                           /* 注意：==0 判断必须在 == 1 判断的前面*/
        } else if (left == 2 && right == 2) {
            return 0;                               /* 未被覆盖状态 */
        }
        return 0;

    }
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (travel(root) == 0) result++;            /* 情况2：如果根节点为未被覆盖状态 */
        return result;
    }
};