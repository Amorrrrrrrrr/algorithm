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
    ListNode* deleteDuplicates(ListNode* head) {
         if (!head) {
            return head;
        }
        
        ListNode* dummyNode = new ListNode(0, head);

        ListNode* cur = dummyNode;
        while (cur->next && cur->next->next) {                                          
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) cur->next = cur->next->next;   /* 跳跃所有的重复元素（需确保 cur->next 非空） */
            } else {
                cur = cur->next;
            }
        }



        return dummyNode->next;
    }
};