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
/* 层序遍历 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int result;
        while (!que.empty()) {
            int size = que.size();
            int i = size;
            while (i--) {
                TreeNode* cur = que.front(); que.pop();
                if (i == size - 1) {                            /* 记录最后一行第一个元素 */
                    result = cur->val;
                }
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return result;
    }
};


/* 递归+回溯(传值方式) */
class Solution {
public:
    int result;
    int maxDepth = INT_MIN;
    void travel(TreeNode* cur, int depth) {
        if (cur->left == NULL && cur->right == NULL) {          /* 回溯的终止条件是叶子节点 */
            if (depth > maxDepth) {
                maxDepth = depth;
                result = cur->val;
            }
            return;
        }
        if (cur->left) {                                        /* 终止条件是叶子节点，因此递归时节点不能为 NULL */
            depth++;
            travel(cur->left, depth);
            depth--;                                            /* 回溯 */
        }
        if (cur->right) {
            depth++;
            travel(cur->right, depth);
            depth--;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        travel(root, 1);
        return result;
    }
};

/* 递归 + 回溯(传引用方式) */
class Solution {
public:
    int result;
    int maxDepth = INT_MIN;
    void travel(TreeNode* cur, int& depth) {
        depth++;
        if (cur->left == NULL && cur->right == NULL) {
            if (depth > maxDepth) {
                maxDepth = depth;
                result = cur->val;
            }
            return;
        }
        if (cur->left) {

            travel(cur->left, depth);
            depth--;
        }
        if (cur->right) {
            //depth++;
            travel(cur->right, depth);
            depth--;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        travel(root, depth);
        return result;
    }
};