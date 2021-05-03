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
    vector<vector<int>> levelOrder(TreeNode* root) {

        std::queue<TreeNode*> qtn;
        if (root) {
            qtn.push(root);
        }

        int size;
        vector<int> v;
        TreeNode* tn;
        vector<vector<int>> result;
        while (!qtn.empty()) {
            size = qtn.size();
            v = {};

            while (size-- > 0) {
                tn = qtn.front();
                qtn.pop();
                v.push_back(tn->val);
                
                if (tn->left) {
                    qtn.push(tn->left);
                }

                if (tn->right) {
                    qtn.push(tn->right);
                }
            }
            result.push_back(v);
        }
        return result;
    }
};
