/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        
        vector<int> result;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            if (st.top() == nullptr) {
                st.pop();
                continue;
            }

            result.push_back(st.top()->val);
            vector<Node*> c = st.top()->children;
            st.pop();
            for (int i = c.size() - 1; i >= 0; i--) {
                st.push(c[i]);
            }
        }
        return result;
    }
};
