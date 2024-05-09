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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* cur = dummyNode;
        while (n--) cur = cur->next;

        ListNode* pre = dummyNode;
        while (cur->next) {
            pre = pre->next;
            cur = cur->next;
        }

        pre->next = pre->next->next;
        return dummyNode->next;
    }
};