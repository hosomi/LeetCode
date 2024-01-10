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
    int amountOfTime(TreeNode* root, int start) {

        map<TreeNode*,TreeNode*> par;
        map<TreeNode*,bool> vis;
        TreeNode* curr = root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                vis[node] = 0;
                if (node->val == start) {
                    curr = node;
                }
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    par[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    par[node->right] = node;
                }
            }
        }

        q.push(curr);
        vis[curr] = 1;
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            bool isIncrement = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (par[node] && !vis[par[node]]) {
                    isIncrement = 1;
                    q.push(par[node]);
                    vis[par[node]] = 1;
                }
                if (node->left && !vis[node->left]) {
                    isIncrement = 1;
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if (node->right && !vis[node->right]) {
                    isIncrement = 1;
                    q.push(node->right);
                    vis[node->right] = 1;
                }
            }
            if (isIncrement) {
                result++;
            }
        }
        return result;
    }
};
