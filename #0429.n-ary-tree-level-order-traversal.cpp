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
    vector<vector<int>> levelOrder(Node* root) {

        if (root == NULL) {
            return vector<vector<int>>();
        }
        
        queue<Node*> q;
        int level = 0;
        int levelCount = 1;
        int nextLevelCount = 0;
        vector<vector<int>> result;
        vector<int> levelAns;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (Node* c : cur->children) {
                if (c != NULL) {
                    q.push(c);
                }
            }
            
            nextLevelCount+=cur->children.size();
            levelAns.push_back(cur->val);
            levelCount--;
            if (levelCount == 0) {
                result.push_back(levelAns);
                levelAns = vector<int>();
                levelCount = nextLevelCount;
                nextLevelCount = 0;
                level++;
            }
        }
        return result;
    }
};
