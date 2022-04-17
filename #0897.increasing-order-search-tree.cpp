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
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode *head = new TreeNode(0);
        TreeNode *pre = head;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            pre -> right = root;
            pre = pre -> right;
            root -> left = NULL;
            root = root -> right;
        }
        return head -> right;
    }
};
