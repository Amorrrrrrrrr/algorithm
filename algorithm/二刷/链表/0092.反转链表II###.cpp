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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(0, head);

        ListNode* leftNode = dummyNode;
        ListNode* rightNode = dummyNode;
        left--;right--;
        while (left--) leftNode = leftNode->next;
        while (right--) rightNode = rightNode->next;

        ListNode* pre = rightNode->next->next;
        ListNode* node = rightNode->next->next;                     /* 终止节点提前记录，避免翻转发生变化 */
        ListNode* cur = leftNode->next;
        while (cur != node) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        leftNode->next = pre;

        return dummyNode->next;
    }
};