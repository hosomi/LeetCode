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
    vector<int> postorder(Node* root) {
        
        stack<Node*> stk;
        stk.push(root);
        vector<int> result;
        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            
            if (node == NULL) {
                continue;
            }
            
            for (Node* child : node->children) {
                stk.push(child);
            }
            
            result.insert(result.begin(), node->val);
        }
        return result;
    }
};
