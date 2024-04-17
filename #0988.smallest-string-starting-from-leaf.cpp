/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {

        string output = "";
        smallestFromLeaf(root, output);
        return result;
    }

private:
    string result = "";
    void smallestFromLeaf(TreeNode *root, string op) {
        
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            if (result == "") {
                result = (char)(root->val + 'a') + op;
            } else{
                result = std::min(result,(char)(root->val + 'a') + op);
            }
        }

        smallestFromLeaf(root->left, (char)(root->val + 'a') + op);
        smallestFromLeaf(root->right, (char)(root->val + 'a') + op);
    }
};
