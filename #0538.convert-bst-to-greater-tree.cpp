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
    TreeNode* convertBST(TreeNode* root) {
        
        bst(root);
        return root;
    }
    
private:
    int sum = 0;

    void bst(TreeNode* root) {

        if (!root) {
            return;
        }

        if (root->right) {
            bst(root->right);
        }

        int temp = root->val;
        root->val += sum;
        sum += temp;
        if (root->left) {
            bst(root->left);
        }
    }
};
