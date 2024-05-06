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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;

        vector<ListNode*> vec;
        ListNode* cur = head;

        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
        }

        for (int left = 0, right = vec.size() - 1; left < right; left++, right--) {
            if (vec[left]->val != vec[right]->val) return false;
        }
        return true;
    }
};