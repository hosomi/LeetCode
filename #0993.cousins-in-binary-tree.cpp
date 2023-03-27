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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int x_level = 0;
        int y_level = 0;
        while(!q.empty()) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr) {
                    if ((curr->left && curr->right)
                        && ((curr->left->val == x
                        && curr->right->val == y) 
                        || (curr->left->val == y
                        && curr->right->val == x))) {
                        return false;
                    }
                }

                if (curr->val == x) {
                    x_level = level;
                }

                if (curr->val == y) {
                    y_level = level;
                }
                
                if (curr->left) {
                    q.push(curr->left);
                }

                if (curr->right) {
                    q.push(curr->right);
                }
            }

        }
        return x_level == y_level;
    }
};
