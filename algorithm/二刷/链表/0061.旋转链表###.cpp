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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;

        ListNode* dummyNode = new ListNode(0, head);
        ListNode* right = head;
        ListNode* left = head;
        int len = 0;
        while (right) {
            len++;
            right = right->next;
        }

        int size = k % len;
        if (size == 0) return dummyNode->next;          /* 不旋转逻辑 */

        right = head;
        while (size--) {
            right = right->next;
        }

        while (right->next) {
            right = right->next;
            left = left->next;
        }


        ListNode* tmp = dummyNode->next;                /* 旋转逻辑 */
        dummyNode->next = left->next;
        left->next = NULL;
        right->next = tmp;

        return dummyNode->next;

    }
};