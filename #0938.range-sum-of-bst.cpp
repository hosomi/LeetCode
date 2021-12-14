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
    int rangeSumBST(TreeNode* root, int low, int high) {

        int result = 0;
        stack<TreeNode*> st = stack<TreeNode*>();
        TreeNode* node;
        st.push(root);
        while (!st.empty()) {
            node = st.top();
            st.pop();
            
            if (node->val >= low && node->val <= high) {
                result+=node->val;
            }
            if (node->left && node->val >= low) {
                st.push(node->left);
            }
            if (node->right && node->val <= high) {
                st.push(node->right);
            }
        }
        return result;
    }
};
