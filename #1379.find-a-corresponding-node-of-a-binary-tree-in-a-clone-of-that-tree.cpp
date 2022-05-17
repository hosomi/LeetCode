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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        if (cloned == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(cloned);
        while (q.size()) {
            if (q.front() != NULL && q.front()->val == target->val) {
                return q.front();
            }
    
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left!=NULL) {
                q.push(temp->left);
            }
            if (temp->right!=NULL) {
               q.push(temp->right);
            }
        }
        return nullptr;
    }
};
