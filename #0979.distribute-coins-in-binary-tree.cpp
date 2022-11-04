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
    int distributeCoins(TreeNode* root) {
        
        this->tree(root);
        return result;
    }

private:
    int result = 0;
    
    int tree(TreeNode* node) {

        if (node == NULL) {
            return 0;
        }
        
        int left = tree(node->left);
        int right = tree(node->right);
        result += abs(left) + abs(right);
        return node->val - 1 + left + right;
    }
};
