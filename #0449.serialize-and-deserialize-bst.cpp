/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string s;
        serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.empty()) {
            return nullptr;
        }
        
        std::istringstream ss(data);
        queue<string> q;
        string s;
        while(ss >> s){
            q.push(s);
        }
        return deserialize(q, INT_MIN, INT_MAX);
    }

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
private:
    void serialize(TreeNode* n, string& s) {

        if (!n) {
            s += "# ";
            return;
        }
        
        s += to_string(n->val) + " ";
        serialize(n->left, s);
        serialize(n->right, s);
    }

    TreeNode* deserialize(queue<string>& q, int lower, int upper) {

        if (q.front() == "#") { 
            q.pop(); 
            return nullptr; 
        }
        
        int val = std::stoi(q.front());
        q.pop();
        
        TreeNode* n = new TreeNode(val);
        n->left = deserialize(q, lower, val);
        n->right = deserialize(q, val, upper);
        return n;
    }
};
