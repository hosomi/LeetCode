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
    int minCameraCover(TreeNode* root) {

        if (root == nullptr) {
            return total;
        }

        if (dfs(root) == 1) {
            ++total;
        }
        return total;
    }

private:
    int total = 0;

    int dfs(TreeNode *root) {

        if (root == nullptr) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == 1 || right == 1) {
            ++total;
            return 2;
        }

        return left == 2 || right == 2 ? 0 : 1;
    }
};
