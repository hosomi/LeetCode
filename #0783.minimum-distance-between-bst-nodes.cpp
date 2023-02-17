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
    int minDiffInBST(TreeNode* root) {
        
        if (!root) {
            return INT_MAX;
        }

        minDiffInBST(root->left);
        result = std::min(result, abs(root->val - prev));
        prev = root->val;
        minDiffInBST(root->right);
        return result;
    }

private:
    int prev = INT_MAX;
    int result = INT_MAX;
};
