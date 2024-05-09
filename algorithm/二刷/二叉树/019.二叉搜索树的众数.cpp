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
    TreeNode* pre = NULL;
    vector<int> result;
    int size = 1;
    int maxSize = 1;
    void travel(TreeNode* cur) {
        if (cur == NULL) return;

        travel(cur->left);
        if (pre == NULL) {
            result.push_back(cur->val);
        } 
        else {
            if (cur->val != pre->val) {
                size = 1;
                if (size == maxSize) {
                    result.push_back(cur->val);
                }
            }
            else {
                size++;
                if (size > maxSize) {
                    result.clear();
                    result.push_back(cur->val);
                    maxSize = size;
                } else if (size == maxSize) {
                    result.push_back(cur->val);
                }
            }
        }
        pre = cur;
        travel(cur->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        result.clear();
        travel(root);
        return result;
    }
};