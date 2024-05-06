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
/* ������� */
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
                if (i == size - 1) {                            /* ��¼���һ�е�һ��Ԫ�� */
                    result = cur->val;
                }
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return result;
    }
};


/* �ݹ�+����(��ֵ��ʽ) */
class Solution {
public:
    int result;
    int maxDepth = INT_MIN;
    void travel(TreeNode* cur, int depth) {
        if (cur->left == NULL && cur->right == NULL) {          /* ���ݵ���ֹ������Ҷ�ӽڵ� */
            if (depth > maxDepth) {
                maxDepth = depth;
                result = cur->val;
            }
            return;
        }
        if (cur->left) {                                        /* ��ֹ������Ҷ�ӽڵ㣬��˵ݹ�ʱ�ڵ㲻��Ϊ NULL */
            depth++;
            travel(cur->left, depth);
            depth--;                                            /* ���� */
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

/* �ݹ� + ����(�����÷�ʽ) */
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