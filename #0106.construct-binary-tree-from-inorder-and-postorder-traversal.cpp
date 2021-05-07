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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> umorder;
        for (int i = 0; i < inorder.size(); i++) {
            umorder[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> buildTree = [&](
            int left, int right, int leftindex, int rightindex) {

            if (leftindex > rightindex) {
                return (TreeNode*)nullptr;
            }

            int order = umorder[postorder[rightindex]];
            int index = leftindex + (order - left) - 1;

            auto root = new TreeNode(postorder[rightindex]);
            root->left = buildTree(left, order - 1, leftindex, index);
            root->right = buildTree(order + 1, right, index + 1, rightindex - 1);
            return root;
        };

        return buildTree(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
