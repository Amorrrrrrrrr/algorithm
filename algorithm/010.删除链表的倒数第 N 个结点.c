
struct ListNode {
    int val;
    struct ListNode *next;
};
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 双指针解法 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));  /* 虚拟头节点：避免删除头节点问题 */
    node->next = head;
    struct ListNode* left = node;
    struct ListNode* right = head;

    while (n-- && right) {                                                      /* 快指针走 n+1 步 */
        right = right->next;
    }

    while (right) {
        right = right->next;
        left = left->next;
    }

    struct ListNode* tmp = left->next;
    left->next = left->next->next;
    free(tmp);

    return node->next;
}