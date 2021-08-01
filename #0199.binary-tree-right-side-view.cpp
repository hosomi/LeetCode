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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        if (root == NULL){
            return result ;
        }

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,0));
        while (!q.empty()){
            TreeNode *node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (depth == result.size()) {
                result.push_back(node->val);
            } else {
                result[depth] = node->val;
            }

            if (node->left){
                q.push(make_pair(node->left, depth + 1));
            }

            if (node->right) {
                q.push(make_pair(node->right, depth + 1));
            }
        }
        return result;
    }
};
