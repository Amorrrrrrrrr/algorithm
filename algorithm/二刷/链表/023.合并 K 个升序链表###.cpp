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

/* ���ȼ����� */
class Solution {
public:
    struct Cmp {
        bool operator() (ListNode* p1, ListNode* p2) {
            return p1->val > p2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pri_que;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pri_que.push(lists[i]);                   /* ע�⣺�ڵ���ڲż�������� */
        }

        ListNode* dummyNode = new ListNode(0, NULL);
        ListNode* cur = dummyNode;

        while (!pri_que.empty()) {
            ListNode* tmp = pri_que.top();
            pri_que.pop();
            cur->next = tmp;
            cur = cur->next;
            if (tmp->next) pri_que.push(tmp->next);
        }

        return dummyNode->next;
    }
};

/* ������������ */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyNode = new ListNode(0, NULL);
        ListNode* cur = dummyNode;

        while (1) {
            ListNode* tmp = NULL;
            int tmpValue = INT_MAX;

            int index = 0;
            int isGood = false;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && lists[i]->val < tmpValue) {
                    tmpValue = lists[i]->val;
                    tmp = lists[i];
                    index = i;
                    isGood = true;
                }
            }
            if (isGood == false) break;
            lists[index] = lists[index]->next;
            cur->next = tmp;
            cur = cur->next;

        }
        return dummyNode->next;
    }
};