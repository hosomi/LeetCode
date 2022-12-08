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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaf1;
        vector<int> leaf2;
        leafValues(root1, &leaf1);
        leafValues(root2, &leaf2);
        return leaf1 == leaf2; 
    }

private:

    void leafValues(TreeNode* root, vector<int>* leaf) {

        stack<TreeNode*> stk;
        TreeNode* cur;
        
        stk.push(root);
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();
            
            if (cur->left == NULL && cur->right == NULL) {
                leaf->push_back(cur->val);
                continue;
            }

            if (cur->right) {
                stk.push(cur->right);
            }

            if (cur->left) {
                stk.push(cur->left);
            }
        }
    }
};
