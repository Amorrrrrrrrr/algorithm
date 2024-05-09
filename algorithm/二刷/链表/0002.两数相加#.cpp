/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* dummy1 = new ListNode(0, l1);
        ListNode* dummy2 = new ListNode(0, l2);

        ListNode* cur1 = dummy1;
        ListNode* cur2 = dummy2;
        while (cur1->next != NULL && cur2->next != NULL) {              /* 双链表部分 */
            cur1->next->val = cur1->next->val + cur2->next->val + sum;
            sum = cur1->next->val / 10;
            cur1->next->val = cur1->next->val % 10;

            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        if (cur2->next != NULL) cur1->next = cur2->next;

        while (cur1->next != NULL && sum != 0) {                        /* 单链表部分 */
            cur1->next->val = cur1->next->val + sum;
            sum = cur1->next->val / 10;
            cur1->next->val = cur1->next->val % 10;

            cur1 = cur1->next;
        }
        if (sum != 0) {                                                 /* 额外部分 */
            cur1->next = new ListNode(sum, NULL);
        }
        return l1;
    }
};