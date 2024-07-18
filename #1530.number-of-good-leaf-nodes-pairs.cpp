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
    int countPairs(TreeNode* root, int distance) {

        result = 0;
        dfs(root, distance);
        return result;
    }

private:
    int result;
    vector<int> dfs(TreeNode *node, int d) {

        vector<int> v(d + 1, 0);
        if (!node) {
            return v;
        }

        if (!node->left and !node->right) {
            v[1] = 1;
            return v;
        }

        vector<int> left = dfs(node->left, d);
        vector<int> right = dfs(node->right, d);
        for (int i = 1; i < d; i++) {
            for (int j = d - i; j >= 1; j--) {
                result += left[i] * right[j];
            }
        }

        for (int i = 2; i < d; i++) {
            v[i] = left[i-1] + right[i-1];
        }
        return v;        
    }
};
