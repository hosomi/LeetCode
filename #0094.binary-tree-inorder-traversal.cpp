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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;
        if (root == NULL) {
            return result;
        }

        stack<TreeNode*> st;
        TreeNode *tn = root;
        while (!st.empty() || tn) {
            if (tn) {
                st.push(tn);
                tn = tn->left;
            } else {
                tn = st.top();
                st.pop();
                result.push_back(tn->val);
                tn = tn->right;
            }
        }
        return result;
    }
};
