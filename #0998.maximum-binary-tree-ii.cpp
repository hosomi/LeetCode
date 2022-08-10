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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {

        TreeNode *node = new TreeNode(val), *cur = root;
        if (root->val < val) {
            node->left = root;
            return node;
        }

        while (cur->right && cur->right->val > val) {
            cur = cur->right;
        }

        node->left = cur->right;
        cur->right = node;
        return root;
    }
};
