class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val, ListNode* next) : val(val), next(next) {}
    } ;

    MyLinkedList() {
        dummyNode = new ListNode(0, NULL);
    }
    
    int get(int index) {
        ListNode* cur = dummyNode;
        while (cur->next != NULL && index != 0) {
            cur = cur->next;
            index--;
        }
        if (cur->next != NULL) return cur->next->val;
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val, NULL);
        node->next = dummyNode->next;
        dummyNode->next = node;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val, NULL);
        ListNode* cur = dummyNode;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* node = new ListNode(val, NULL);
        ListNode* cur = dummyNode;
        while (cur->next != NULL && index != 0) {
            cur = cur->next;
            index--;
        }
        if (cur->next) {
            node->next = cur->next;
            cur->next = node;
        } else if (index == 0) {
            cur->next = node;
        }
    }
    
    void deleteAtIndex(int index) {
        ListNode* cur = dummyNode;
        while (cur->next != NULL && index != 0) {
            cur = cur->next;
            index--;
        }
        if (cur->next) 
            cur->next = cur->next->next;
    }

    ListNode* dummyNode;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */