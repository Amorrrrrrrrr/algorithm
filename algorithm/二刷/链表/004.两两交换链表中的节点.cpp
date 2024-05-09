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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummyNode = new ListNode(0, head);

        ListNode* left = dummyNode;
        ListNode* mid = head;
        ListNode* right = head->next;

        while (1) {
            mid->next = right->next;
            right->next = mid;
            left->next = right;

            left = mid;
            if (left->next == NULL || left->next->next == NULL) break;
            mid = left->next;
            right = left->next->next;
        }

        return dummyNode->next;
    }
};