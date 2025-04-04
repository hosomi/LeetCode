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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        if (root == NULL) {
            return NULL;
        }

        if (height(root->left) == height(root->right)) {
            return root;
        }

        return height(root->left) > height(root->right) ?
            lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
    }

private:
    int height(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }
        
        int l = height(root->left);
        int r = height(root->right);
        return l > r ? l + 1 : r + 1;
    }
};
