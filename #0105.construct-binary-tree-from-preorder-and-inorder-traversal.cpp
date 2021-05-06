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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (preorder.empty()) {
            return nullptr;
        }

        TreeNode* result = new TreeNode(preorder[0]);
        int index = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> vinorder(inorder.begin(), inorder.begin() + index);
        vector<int> vpreorder(preorder.begin() + 1, preorder.begin() + 1 + vinorder.size());
        result->left = buildTree(vpreorder, vinorder);

        vpreorder = {preorder.begin() + 1 + vinorder.size(), preorder.end()};
        vinorder = {inorder.begin() + index + 1, inorder.end()};
        result->right = buildTree(vpreorder, vinorder);

        return result;
    }
};
