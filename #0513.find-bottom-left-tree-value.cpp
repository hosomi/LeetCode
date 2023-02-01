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
    int findBottomLeftValue(TreeNode* root) {
        
        pair<int,int> result = {0, root->val};
        findBottomLeftValue(root, 0, result);
        return result.second;
    }

private:
    void findBottomLeftValue(TreeNode* root, int level,
        pair<int,int>& result) {

        if (!root) {
            return;
        }

        if (level>result.first) {
            result = {level, root->val};
        }

        findBottomLeftValue(root->left, level + 1, result);
        findBottomLeftValue(root->right, level + 1, result);
    }
};
