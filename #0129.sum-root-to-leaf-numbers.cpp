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
    int sumNumbers(TreeNode* root) {

        calcSumRootToLeafNodes(root, 0);
        return sum;
    }
    
private:
    int sum = 0;
    void calcSumRootToLeafNodes(TreeNode *root, int num) {

        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            sum += num * 10 + root->val;
            return;
        }

        calcSumRootToLeafNodes(root->left, num * 10 + root->val);
        calcSumRootToLeafNodes(root->right, num * 10 + root->val);
    }
};
