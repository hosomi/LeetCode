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
    vector<string> binaryTreePaths(TreeNode* root) {

        if (root == NULL) {
            return vector<string>();
        }

        if (!root->left && !root->right) {
            return vector<string> {to_string(root->val)};
        }
        
        vector<string> result;
        if (root->left) {
            for (string s : binaryTreePaths(root->left)) {
                result.push_back(to_string(root->val) + "->" + s);
            }
        }

        if (root->right) {
            for (string s : binaryTreePaths(root->right)) {
                result.push_back(to_string(root->val) + "->" + s);
            }
        }
        return result;
    }
};
