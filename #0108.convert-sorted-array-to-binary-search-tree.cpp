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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        function<TreeNode*(int left, int right)> binarySearchTree = [&](int left, int right) {
            if (left > right) {
                return static_cast<TreeNode*>(nullptr);
            }
            int middle = left + (right - left) / 2;
            TreeNode* root = new TreeNode(nums[middle]);
            root->left = binarySearchTree(left, middle - 1);
            root->right = binarySearchTree(middle + 1, right);
            return root;
        };
        return binarySearchTree(0, nums.size() - 1);
    }
};
