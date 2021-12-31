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
    int maxAncestorDiff(TreeNode* root) {

        int result = 0;
        ancestorDiff(root->left, root->val, root->val, result);
        ancestorDiff(root->right, root->val, root->val, result);
        return result;
    }

private:
    void ancestorDiff(TreeNode* root, int max, int min, int& result) {

        if (!root) {
            return;
        }

        result = std::max(result, std::abs(root->val - max));
        result = std::max(result, std::abs(root->val - min));
        max = std::max(max, root->val);
        min = std::min(min, root->val);
        ancestorDiff(root->left, max, min, result);
        ancestorDiff(root->right, max, min, result);
    }
};
