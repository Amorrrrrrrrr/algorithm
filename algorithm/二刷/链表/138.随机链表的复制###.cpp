/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        Node* cur = head;
        unordered_map<Node*, Node*> map; 
        while (cur) {
            map.insert(pair<Node*, Node*>(cur, new Node(cur->val)));        /* 每个新节点与当前节点相关联 */
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            map[cur]->next = map[cur->next];                                /* new = map[cur];
                                                                               new->next = map[cur->next] */
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        return map[head];
    }
};