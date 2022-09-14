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
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int r = 0;
        this->pseudoPalindromicPaths(root, r);
        return r;
    }

private:
    map<int,int> m;

    void pseudoPalindromicPaths(TreeNode *root,int &r) {

        if (!root) {
            return;
        }
        
        m[root->val]++;
        this->pseudoPalindromicPaths(root->left, r);
        this->pseudoPalindromicPaths(root->right, r);
        int index = 0;
        if (!root->left && !root->right) {
            for (auto a : m) {
                if (a.second%2) {
                    index++;
                }
            }

            if (index <= 1) {
                r++;
            }
        }
        m[root->val]--;
    }
};
