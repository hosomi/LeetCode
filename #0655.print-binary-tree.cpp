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
    vector<vector<string>> printTree(TreeNode* root) {
        
        int h = height(root);
        vector<vector<string>> result(h, vector<string>(pow(2,h)-1, ""));

        int col = result[0].size();
        traversal(root, 0, col / 2, 0, col - 1, result);
        return result;
    }

private:
    int height(TreeNode* root) {

        if (!root) {
            return 0;
        }

        return 1 + std::max(height(root->left), height(root->right));
    }
    
    void traversal(TreeNode* root, int i, int j,
        int k, int l, vector<vector<string>> &result) {
        
        if (!root) {
            return;
        }

        result[i][j] = to_string(root->val);
        traversal(root->left, i + 1, (k + j) / 2, k, j, result);
        traversal(root->right, i + 1, (l + j) / 2 + (l + j) % 2, j, l, result);
    }
};
