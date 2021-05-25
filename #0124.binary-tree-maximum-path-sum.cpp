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
    int maxPathSum(TreeNode* root) {

        int max = INT_MIN;
        maxPathRoot(root, max);
        return max;
    }

private:
    int maxPathRoot(TreeNode *root, int &max) {

        if (!root) {
            return 0;
        }

        int left = maxPathRoot(root->left, max);
        if (left < 0) {
            left = 0;
        }

        int right = maxPathRoot(root->right, max);
        if(right < 0) {
            right = 0;
        }

        if (left + right + root->val > max) {
            max = left + right + root-> val;
        }
        return root->val + std::max(left, right);
    }
};
