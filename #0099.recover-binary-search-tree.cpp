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
    void recoverTree(TreeNode* root) {

        firstTree(root);
        sort(work.begin(), work.end());

        int index = 0;
        lastTree(root, index);
    }

private:
    vector <int> work;

    void firstTree(TreeNode* root) {

        if (root == NULL) {
            return;
        }

        firstTree(root->left);
        work.push_back(root->val);
        firstTree(root->right);
    }
    
    void lastTree(TreeNode* root, int&index) {

        if (root == NULL) {
            return;
        }

        lastTree(root->left, index);
        root->val = work[index++];
        lastTree(root->right, index);
    }
};
