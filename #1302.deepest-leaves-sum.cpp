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
    int deepestLeavesSum(TreeNode* root) {

        int result = 0;
        int curLevelCount = 0;
        int nextLevelCount = 0;
        queue<TreeNode*> q;
        TreeNode *node;
        q.push(root);
        curLevelCount++;
        while (!q.empty()) {
            node = q.front(); q.pop();
            curLevelCount--;
            result += node->val;
            
            if (node->left) {
                q.push(node->left);
                nextLevelCount++;
            }
            
            if (node->right) {
                q.push(node->right);
                nextLevelCount++;
            }
            
            if (curLevelCount == 0) {
                curLevelCount = nextLevelCount;
                nextLevelCount = 0;
                if (!q.empty()) {
                    result = 0;
                }
            }
        }
        return result;
    }
};
