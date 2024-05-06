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

/* ÅÅÐòËã·¨µÄÕÆÎÕ */
class Solution {
public:
    static bool mycompare(ListNode* p1, ListNode* p2) {
        return p1->val < p2->val;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        vector<ListNode*> vec;
        ListNode* cur = head;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
        }

        sort(vec.begin(), vec.end(), mycompare);
        int i = 0;
        for (; i < vec.size() - 1; i++) {
            vec[i]->next = vec[i + 1];
        }
        vec[i]->next = NULL;
        return vec[0];
    }
};