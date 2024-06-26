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
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> in;
        inorder(root, in);
        return buildTree(in, 0, in.size() - 1);
    }

private:
    void inorder(TreeNode* root, vector<int>& in) {
        
        if (!root) {
            return;
        }

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode* buildTree(vector<int>& in, int st, int end) {

        if (st > end) {
            return NULL;
        }

        int mid = (st+end)>>1;
        TreeNode* root= new TreeNode(in[mid]);
        root->left = buildTree(in, st, mid - 1);
        root->right = buildTree(in, mid + 1, end);
        return root;
    }
};
