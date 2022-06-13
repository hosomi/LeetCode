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
    int longestUnivaluePath(TreeNode* root) {

        path(root);
        return result;
    }
    
private:
    int result = 0;
    int path(TreeNode* node) {

        if (!node) {
            return 0;
        }

        int left = path(node->left);
        int right = path(node->right);
        int l = 0;
        int r = 0;
        if (node->left && node->left->val == node->val) {
            l = left+1;
        }

        if(node->right && node->right->val == node->val) {
            r = right+1;
        }

        result = std::max(result, l + r);
        return std::max(l, r);
    }
};
