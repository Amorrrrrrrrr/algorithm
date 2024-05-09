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

 /* 前序遍历：让父节点指向它的孩子节点 */
 /* 回溯：回溯和递归相辅相成，只要有递归就一定有回溯，回溯的过程就在递归函数的下面 */
 /* 回溯的过程：收集路径的容器把子节点弹出去，回退到父节点，再重新把另一个子节点加进来，那这个过程其实就是回溯的过程 */
class Solution {
public:
    void                            /* path 容器：用来记录单条路径 */
}