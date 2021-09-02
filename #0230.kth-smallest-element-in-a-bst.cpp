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
    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*> st;
        TreeNode* cursor = root;
        do {
            while (cursor) {
                st.push(cursor);
                cursor = cursor->left;
            }

            cursor = st.top(); st.pop();
            if (--k == 0) {
                return cursor->val;
            }

            cursor = cursor->right;
        } while(!st.empty() || cursor);
        return 0;
    }
};
