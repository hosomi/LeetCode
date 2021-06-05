/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (!node) {
            return node;
        }

        if (result.find(node) != result.end()) {
            return result[node];
        }
        
        result[node] = new Node(node->val);
        for (Node* n : node->neighbors) {
            result[node]->neighbors.push_back(cloneGraph(n));
        }
        return result[node];
    }

private:
    unordered_map<Node*, Node*> result;
};
