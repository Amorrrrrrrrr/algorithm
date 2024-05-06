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

/* 使用虚拟头节点连接遍历过的节点 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(0, NULL);
        ListNode* cur = dummyNode;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }
        if (list1 != NULL) cur->next = list1;
        else cur->next = list2;

        return dummyNode->next;

    }
};