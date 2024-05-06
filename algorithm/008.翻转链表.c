
struct ListNode {
    int val;
    struct ListNode *next;
};
 
/* 三指针解法：cur、pre 和 tmp*/

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

/* 递归写法 */
struct ListNode* reverse(struct ListNode* cur, struct ListNode* pre) {
    if (!cur) return pre;

    struct ListNode* tmp = cur->next;
    cur->next = pre;
    return reverse(tmp, cur);                               /* 递归最后要返回返回类型*/
}

struct ListNode* reverseList(struct ListNode* head) {
    return reverse(head, NULL);
}