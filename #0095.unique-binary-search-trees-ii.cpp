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
    vector<TreeNode*> generateTrees(int n) {

        vector<vector<TreeNode*>> v(n + 1);
        TreeNode* tn;
        v[0] = {nullptr};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                for (TreeNode* lefttn : v[j - 1]) {
                    for (TreeNode* righttn : v[i - j]) {
                        tn = new TreeNode(j);
                        tn->left = lefttn;
                        tn->right = bst(righttn, j);
                        v[i].push_back(tn);
                    }
                }
            }
        }
        return v[n];
    }

private:

    TreeNode* bst(TreeNode* tn, int offset) {

        if (!tn) {
            return nullptr;
        }

        TreeNode* tnwork = new TreeNode(tn->val + offset);
        tnwork->left = bst(tn->left, offset);
        tnwork->right = bst(tn->right, offset);

        return tnwork;
    }
};
