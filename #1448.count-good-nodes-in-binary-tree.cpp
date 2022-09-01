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
    int goodNodes(TreeNode* root) {

        this->goodNodes(root, root->val);
        return tree;
    }

private:
    int tree = 0;

    void goodNodes(TreeNode* node, int upper) {

        if (node == nullptr) {
            return;
        }

        if (node->val >= upper) {
            tree++;
        }
        this->goodNodes(node->left, std::max(node->val, upper));
        this->goodNodes(node->right, std::max(node->val, upper));
    };
};
