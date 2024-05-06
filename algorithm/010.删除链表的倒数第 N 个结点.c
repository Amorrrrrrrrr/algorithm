
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

/* ˫ָ��ⷨ */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));  /* ����ͷ�ڵ㣺����ɾ��ͷ�ڵ����� */
    node->next = head;
    struct ListNode* left = node;
    struct ListNode* right = head;

    while (n-- && right) {                                                      /* ��ָ���� n+1 �� */
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