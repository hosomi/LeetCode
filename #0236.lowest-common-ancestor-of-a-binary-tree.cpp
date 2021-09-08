/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        unordered_map<TreeNode*, TreeNode*> ancestor;
        stack<TreeNode*> st;
        TreeNode *cursor;
        ancestor[root] = nullptr;
        st.push(root);
        while (ancestor.find(p) == ancestor.end()
               || ancestor.find(q) == ancestor.end()) {

            cursor = st.top();
            st.pop();
            if (cursor->left) {
                ancestor[cursor->left] = cursor;
                st.push(cursor->left);
            }

            if (cursor->right) {
                ancestor[cursor->right] = cursor;
                st.push(cursor->right);
            }
        }

        set<TreeNode*> s;
        while (p) {
            s.insert(p);
            p = ancestor[p];
        }

        while (s.find(q) == s.end()) {
            q = ancestor[q];
        }
        return q;
    }
};
