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

        if (!head) {
            return NULL;
        }

        Node* result = new Node(head->val, NULL, NULL);
        Node* n = result;
        Node* cursor = head->next;
        map<Node*,Node*> m;
        Node* work;
        m[head] = result;
        m[NULL] = NULL;
        while (cursor) {
            work = new Node(cursor->val, NULL, NULL);
            n->next = work;
            m[cursor] = work;
            n = n->next;
            cursor = cursor->next;
        }

        n = result;
        cursor = head;
        while (n) { 
            if (!cursor->random) {
                n->random = NULL;
            } else {
                n->random = m[cursor->random];
            }
            n = n->next;
            cursor = cursor->next;
        }
        return result;
    }
};
