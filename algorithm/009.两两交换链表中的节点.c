
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

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->next = head;

    struct ListNode* cur = node;
    while (cur->next && cur->next->next) {              /* охеп╤о cur->next тыеп╤о cur->next->next */
        struct ListNode* tmp = cur->next->next->next;
        cur->next->next->next = cur->next;
        cur->next = cur->next->next;
        cur->next->next->next = tmp;

        cur = cur->next->next;
    }
    return node->next;
}