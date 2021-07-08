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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {

        TreeNode* cursor = root;
        while (cursor) {
            st.push(cursor);
            cursor = cursor->left;
        }
    }
    
    int next() {

        TreeNode* cursor = st.top();
        st.pop();
        TreeNode* tn = cursor->right;
        while (tn) {
            st.push(tn);
            tn = tn->left;
        }
        return cursor->val;
    }
    
    bool hasNext() {

        return !st.empty();
    }

private:
    stack<TreeNode*> st;

};



/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
