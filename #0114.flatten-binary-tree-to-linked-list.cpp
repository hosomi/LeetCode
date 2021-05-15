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
    void flatten(TreeNode* root) {

        if (!root) {
            return;
        }

        std::stack<TreeNode*> st;
        TreeNode *tn;
        TreeNode *tnr;
        st.push(root);
        while (!st.empty()) {
            tn = st.top();
            st.pop();
            if (tn->left) {
                tnr = tn->left;
                while (tnr->right) {
                    tnr = tnr->right;
                }
                tnr->right = tn->right;
                tn->right = tn->left;
                tn->left = NULL;
            }
            if (tn->right) {
                st.push(tn->right);
            }
        }
    }
};
