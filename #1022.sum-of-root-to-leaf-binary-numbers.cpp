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
    int sumRootToLeaf(TreeNode* root) {

        map<TreeNode*, TreeNode*> parent;
        stack<TreeNode*> stk;
        TreeNode* cursor;
        stk.push(root);
        parent[root] = nullptr;
        int result = 0;
        while (!stk.empty()) {
            cursor = stk.top(); stk.pop();
            if (!cursor->left && !cursor->right) {
                int path_val = 0, h = 0 ;
                while (cursor != nullptr) {
                    path_val += (cursor->val << h);
                    h++;
                    cursor = parent[cursor];
                }
                result += path_val;
                continue;
            }

            if (cursor->right) {
                stk.push(cursor->right);
                parent[cursor->right] = cursor;
            }

            if (cursor->left) {
                stk.push(cursor->left);
                parent[cursor->left] = cursor;
            }
        }
        return result;
    }
};
