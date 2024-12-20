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
    TreeNode* reverseOddLevels(TreeNode* root) {

        int level = 0;
        std::deque<TreeNode*> q = { root };
        while (!q.empty()) {
            int n = q.size();
            if (level++ % 2) {
                for (int l = 0, r = n - 1; l < r; l++, r--) {
                    std::swap(q[l]->val, q[r]->val);
                }
            }

            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop_front();
                if (node->left != nullptr) {
                    q.push_back(node->left);
                }
                if (node->right != nullptr) {
                    q.push_back(node->right);
                }
            }
        }
        return root;
    }
};
