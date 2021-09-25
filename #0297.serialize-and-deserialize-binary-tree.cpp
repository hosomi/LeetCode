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

        if (root == nullptr) {
            return "# ";
        }

        string s = std::to_string(root->val) + " ";
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        stringstream ss(data);
        string val;
        queue<string> q;
        while (getline(ss, val, ' ')) {
            q.push(val);
        }
        return tree(q);
    }
    
private:
    TreeNode* tree(queue<string>& q) {

        string s = q.front();
        q.pop();
        if (s == "#") {
            return nullptr;
        }

        TreeNode* n = new TreeNode(std::stoi(s));
        n->left = tree(q);
        n->right = tree(q);
        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
