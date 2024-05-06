
struct ListNode {
    int val;
    struct ListNode *next;
};
 
/* ��ָ��ⷨ��cur��pre �� tmp*/

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;

    while (cur) {
        struct ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

/* �ݹ�д�� */
struct ListNode* reverse(struct ListNode* cur, struct ListNode* pre) {
    if (!cur) return pre;

    struct ListNode* tmp = cur->next;
    cur->next = pre;
    return reverse(tmp, cur);                               /* �ݹ����Ҫ���ط�������*/
}

struct ListNode* reverseList(struct ListNode* head) {
    return reverse(head, NULL);
}