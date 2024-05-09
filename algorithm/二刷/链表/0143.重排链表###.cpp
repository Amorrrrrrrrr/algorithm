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

 /* 逆序链表 + 合并链表 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* dummy1 = new ListNode(0, head);
        ListNode* cur1 = head;
        ListNode* dummy2 = new ListNode(0, NULL);
        int len = 0;
        while (cur1) {
            ListNode* cur2 = new ListNode(cur1->val, NULL);
            cur2->next = dummy2->next;
            dummy2->next = cur2;
            cur1 = cur1->next;
            len++;
        }

        cur1 = dummy1->next;
        ListNode* cur2 = dummy2->next;
        ListNode* after2 = cur2->next;
        int size = (len - 1) / 2;
        bool isAdd = (len - 1) % 2;
        while (size--) {
            cur2->next = cur1->next;
            cur1->next = cur2;

            cur1= cur1->next->next;
            cur2 = after2;
            after2 = after2->next;
        }

        if (isAdd) {
            cur1->next = cur2;
            cur1 = cur1->next;
        }
        cur1->next = NULL;
    }
};

/* 线性表 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};