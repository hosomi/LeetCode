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
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> result;
        if(!root) {
            return result;
        }

        stack<TreeNode*> st;
        st.push(root);
        TreeNode* tn;
        while (!st.empty()) {
            tn = st.top();
            st.pop();
            result.insert(result.begin(), tn->val);

            if (tn->left) {
                st.push(tn->left);
            }

            if (tn->right) {
                st.push(tn->right);
            }
        }
        return result;
    }
};
