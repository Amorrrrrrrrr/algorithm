/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        int sumA = 0;
        while (curA) {
            curA = curA->next;
            sumA++;
        }

        ListNode* curB = headB;
        int sumB = 0;
        while (curB) {
            curB = curB->next;
            sumB++;
        }

        curA = headA;
        curB = headB;

        if (sumA < sumB) {
            swap(sumA, sumB);
            swap(curA, curB);
        }

        int size = sumA - sumB;
        while (size--) curA = curA->next;

        while (curA != NULL && curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }

        return curA;
    }
};