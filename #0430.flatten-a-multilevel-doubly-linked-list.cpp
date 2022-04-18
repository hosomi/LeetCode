/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        if (head == nullptr) {
            return nullptr;
        }

        Node* cur;
        stack<Node*> st;
        st.push(head);        
        Node* newhead = head;     
        while (!st.empty()) {
            cur = st.top(); st.pop();
            while (cur->next != nullptr && cur->child == nullptr) {
                cur = cur->next;
            }
            
            if (cur->next == nullptr && cur->child != nullptr) {
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
                st.push(cur->next);
            } else if(cur->next == nullptr) {
                if (!st.empty()) {
                    cur->next = st.top();
                    st.top()->prev = cur;
                }
            } else {
                st.push(cur->next);
                st.push(cur->child);
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
        }
        return newhead;
    }
};
