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
    TreeNode* pre;
    int size;                                  /* 统计当前元素出现的频率 */
    int maxSize = 0;                           /* 统计元素出现的最高频率 */                 
    vector<int> result;
    void travel(TreeNode* cur) {
        if (cur == NULL) return;

        travel(cur->left);
        if (pre == NULL) {                      /* 统计当前元素出现的频率 */
            size = 1;
        }
        else {
            if (cur->val == pre->val) {
                size += 1;
            }
            else {
                size = 1;
            }
        }
        if (size > maxSize) {                   /* 收获结果集 */
            result.clear();
            result.push_back(cur->val);
            maxSize = size;
        } else if (size == maxSize) {
            result.push_back(cur->val);
        }
        pre = cur;
        travel(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        travel(root);
        return result;
    }
};