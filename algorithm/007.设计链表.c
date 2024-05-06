
typedef struct MyLinkedList {
	int val;
	struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {

}

int myLinkedListGet(MyLinkedList* obj, int index) {

}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	node->val = val;

	MyLinkedList* cur = obj;
	while (cur->next) {
		if (index != 0) {
			cur = cur->next;
			index--;
		}
		else {
			node->next = cur->next;
			cur->next = node;
		}
	}
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	MyLinkedList* cur = obj;
	while (cur->next) {
		if (index != 0) {
			cur = cur->next;
			index--;
		}
		else {
			MyLinkedList* node = cur->next;
			cur->next = cur->next->next;
			free(node);
		}
	}
}

void myLinkedListFree(MyLinkedList* obj) {
	while (obj != NULL) {
		MyLinkedList* tmp = obj;
		obj = obj->next;
		free(tmp);
	}
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/