/* 形式 1 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if (root->val == val) return root;

        TreeNode* result;
        if (root->val > val) {
            result = searchBST(root->left, val);
        }
        if (root->val < val) {
            result = searchBST(root->right, val);
        }
        return result;
    }
};

/* 形式 2 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if (root->val == val) return root;

        if (root->val > val) {
            return searchBST(root->left, val);
        }
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        return NULL;
    }
};

/* 形式 3 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;

        if (root->val > val) {
            return searchBST(root->left, val);
        }
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        return root;
    }
};