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
    int getMinimumDifference(TreeNode* root) {

        helper(root);
        return min;
    }

private:
    int last = INT_MIN / 2;
    int min = INT_MAX;
    
    void helper(TreeNode* node) {

        if (node->left) {
            helper(node->left);
        }

        min = std::min(min, node->val - last);
        last = node->val;
        if (node->right) {
            helper(node->right);
        }
    }
};
