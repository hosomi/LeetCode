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
    int rob(TreeNode* root) {

        if (!root) {
            return 0;
        }

        if (m.count(root)) {
            return m[root];
        }

        int left = rob(root->left) + rob(root->right);
        int left2 = root->left ? rob(root->left->left) + rob(root->left->right) : 0;
        int right = root->right ? rob(root->right->left) + rob(root->right->right) : 0;
        int right2 = root->val + left2 + right;
        m[root] = std::max(left, right2);
        return m[root];
    }

private:
    unordered_map<TreeNode*, int> m;
};
