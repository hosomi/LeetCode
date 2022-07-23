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
    TreeNode* bstToGst(TreeNode* root) {

        if (root) {
           self:bst(root);
        }

        return root;
    }
    
private:
    int order = 0;

    void bst(TreeNode* node) {
    
        if (node->right) {
            bst(node->right);
        }
        
        node->val += order;
        order = node->val;
        
        if (node->left) {
            bst(node->left);
        }
    }
};
