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
    int maxLevelSum(TreeNode* root) {

        vector<int> levelSums;
        dfs(root, levelSums, 0);
        return distance(levelSums.begin(), 
            max_element(levelSums.begin(), levelSums.end())) + 1;
    }

private:
    void dfs(TreeNode* node, vector<int>& levelSums, int level) {

        if (!node) {
            return;
        }

        if (level == levelSums.size()) {
            levelSums.push_back(node->val);
        } else {
            levelSums[level] += node->val;
        }
        
        if (node->left) {
            dfs(node->left, levelSums, level+1);
        }

        if (node->right) {
            dfs(node->right, levelSums, level+1);
        }
    };
};
