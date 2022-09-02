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
    vector<double> averageOfLevels(TreeNode* root) {

        if (!root) {
            return {};
        }

        queue<TreeNode*> q;
        vector<int> v;
        int size;
        TreeNode *curr;
        vector<double> result;

        q.push(root);
        while (q.size()) {
            v.clear();
            size = q.size();
            for (int i = 0; i < size; i++) {
                curr = q.front();
                v.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }

                if (curr->right) {
                    q.push(curr->right);
                }
                q.pop();
            }
            result.push_back(std::accumulate(begin(v), end(v), 0.0) / v.size());
        }
        return result;
    }
};
