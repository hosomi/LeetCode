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
    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;
        diameterOfBinaryTree(root, diameter);
        return diameter;
    }

private:
    int diameterOfBinaryTree(TreeNode* node, int& diameter) {
    
        if (!node) {
            return 0;
        }

        int left = diameterOfBinaryTree(node->left, diameter);
        int right = diameterOfBinaryTree(node->right, diameter);
        diameter = std::max(diameter, left + right);
        return 1 + std::max(left, right);
    }
};
