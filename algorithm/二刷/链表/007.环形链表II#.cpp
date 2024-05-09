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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL ) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) break;
        }

        if (fast->next == NULL || fast->next->next == NULL) return NULL;        /* 没有找到环的处理逻辑 */

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};