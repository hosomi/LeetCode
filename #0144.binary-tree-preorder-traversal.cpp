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

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> result = {};
        stack<TreeNode*> st;
        TreeNode* tn = root;
        while (!st.empty() || tn) {
            while (tn) {
                result.push_back(tn->val);
                st.push(tn);
                tn = tn->left;
            }
            tn = st.top();
            st.pop();
            tn = tn->right;
        }
        return result;
    }
};
