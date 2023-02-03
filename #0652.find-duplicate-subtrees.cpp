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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        repeat = vector<TreeNode*>(0);
        toString(root);
        return repeat;
    }

private:
    unordered_map<string,int> ump;
    vector<TreeNode*> repeat;

    string toString(TreeNode* root) {

        if (root == nullptr) {
            return "x";
        }

        string s = to_string(root->val) + '<'
            + toString(root->left) + toString(root->right);
        if (++ump[s] == 2) {
            repeat.push_back(root);
        }
        return s;
    }
};
