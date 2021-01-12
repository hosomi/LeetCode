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
    bool isValidBST(TreeNode* root) {
        return recurse(root, LLONG_MIN, LLONG_MAX);
    }

    bool recurse(TreeNode* node, long long lower, long long upper) {
        if (!node) {
            return true;
        }

        if (node->val <= lower) {
            return false;
        }

        if (node->val >= upper) {
            return false;
        }

        if (!recurse(node->left, lower, node->val)) {
            return false;
        }

        if (!recurse(node->right, node->val, upper)) {
            return false;
        }
        
        return true;
    }
};
