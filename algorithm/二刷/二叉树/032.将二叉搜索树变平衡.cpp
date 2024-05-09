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
    vector<int> treeVec;
    void treeToVec(TreeNode* cur) {
        if (cur == NULL) return ;
        
        treeToVec(cur->left);
        if (pre == NULL) treeVec.push_back(cur->val);
        else treeVec.push_back(cur->val);
        pre = cur;
        treeToVec(cur->right);
    }

    TreeNode* travel(vector<int> treeVec) {
        if (treeVec.size() == 0) return NULL;
        if (treeVec.size() == 1) return new TreeNode(treeVec[0]);

        int index = treeVec.size() / 2;
        TreeNode* cur = new TreeNode(treeVec[index]);
        vector<int> left(treeVec.begin(), treeVec.begin() + index);
        vector<int> right(treeVec.begin() + index + 1, treeVec.end());
        cur->left = travel(left);
        cur->right = travel(right);
        return cur;
    }
    TreeNode* balanceBST(TreeNode* root) {
        treeToVec(root);
        return travel(treeVec);
    }
};