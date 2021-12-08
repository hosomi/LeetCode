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
    int findTilt(TreeNode* root) {

        if (!root) {
            return 0;
        }
        return std::abs(tilt(root->left) - tilt(root->right)) \
            + findTilt(root->left) + findTilt(root->right);
    }

private:
    int tilt(TreeNode* root) {

        if (!root) {
            return 0;
        }
        return root->val + tilt(root->left) + tilt(root->right);
    }
};
