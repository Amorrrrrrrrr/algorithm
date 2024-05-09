/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
   int val;
   struct ListNode *next;
};

/* 使用虚拟头节点 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyNode->next = head;

    struct ListNode* curNode = dummyNode;
    while(curNode->next != NULL) {
        if (curNode->next->val == val) {
            struct ListNode *tmp = curNode->next;
            curNode->next = curNode->next->next;
            free(tmp);
        } else {
            curNode = curNode->next;
        }
    }

    curNode = dummyNode->next;
    free(dummyNode);
    return curNode;
}

/* 原链表 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {                      /* 注意判断条件 */
        struct ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }

    struct ListNode* curNode = head;
    while(curNode != NULL && curNode->next != NULL) {               /* 注意判断条件 */
        if (curNode->next->val == val) {
            struct ListNode *tmp = curNode->next;
            curNode->next = curNode->next->next;
            free(tmp);
        } else {
            curNode = curNode->next;
        }
    }

    return head;
}