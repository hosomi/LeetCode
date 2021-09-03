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
    int findSecondMinimumValue(TreeNode* root) {

        stack<TreeNode*> s;
        TreeNode* cursor;
        long left = LONG_MAX;
        long right = LONG_MAX;
        s.push(root);
        while (!s.empty()) {
            cursor = s.top();
            s.pop();
            if (cursor->val < left) {
                right = left;
                left = cursor->val;
            } else if (cursor->val > left && cursor->val < right) {
                right = cursor->val;
            }

            if (cursor->left) {
                s.push(cursor->left);
            }

            if (cursor->right) {
                s.push(cursor->right);
            }
        }
        return left == right ? -1 : right;
    }
};
