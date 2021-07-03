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
    bool findTarget(TreeNode* root, int k) {

        queue<TreeNode*> q;
        vector<int> v;
        TreeNode* cursor;

        q.push(root);
        while (!q.empty()) {
            cursor = q.front();
            q.pop();
            
            for (int i : v) {
                if(i + cursor->val==k){
                    return true;
                }
            }

            v.push_back(cursor->val);
            
            if (cursor->left) {
                q.push(cursor->left);
            }

            if (cursor->right) {
                q.push(cursor->right);
            }
        }
        return false;
    }
};
