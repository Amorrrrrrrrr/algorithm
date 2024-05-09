/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int sizeA = 0;
    int sizeB = 0;
    int size;
    struct ListNode * cur = headA;
    while(cur) {
        cur = cur->next;
        sizeA++;
    }

    cur = headB;
    while(cur) {
        cur = cur->next;
        sizeB++;
    }

    struct ListNode* curA = headA;
    struct ListNode* curB = headB; 

    if (sizeA > sizeB) {
        size = sizeA - sizeB;
        while(size--) {
            curA = curA->next;
        }
    } else {
        size = sizeB - sizeA;
        while(size--) {
            curB = curB->next;
        }
    }

    while(curA) {
        if (curA == curB) {
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}