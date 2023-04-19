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
    int longestZigZag(TreeNode* root) {
        
        int result = 0;
        helper(root, 0, 3, result);
        return result;
    }

private:
    void helper(TreeNode*root, int curr, int check, int&result) {

        if (!root) {
            return;
        }

        result = std::max(curr,result);
        int left = check == 0 ? 1 : curr + 1;
        int right = check == 1 ? 1 : curr + 1;
        helper(root->left, left, 0, result);
        helper(root->right, right, 1, result);
    }
};
