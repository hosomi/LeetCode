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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> leaf;
        vector<vector<int>> allLeafs;
        finaLeafSum(root, targetSum, leaf, allLeafs);
        return allLeafs;
    }

private:
    void finaLeafSum(TreeNode *root, int targetSum, vector<int> &leaf, vector<vector<int> > &allLeafs) {

        if (!root) {
            return;
        }

        targetSum -= root->val;
        leaf.push_back(root->val);

        if (!root->left && !root->right) {
            if(targetSum==0) {
                allLeafs.push_back(leaf);
            }
        } else {
            if (root->left) {
                finaLeafSum(root->left, targetSum, leaf, allLeafs);
            }
            if (root->right) {
                finaLeafSum(root->right, targetSum, leaf, allLeafs);
            }
        }
        leaf.pop_back();
    }
};
