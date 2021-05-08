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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        TreeNode* tn;
        queue<TreeNode*> qtn;
        qtn.push(root);
        int size;
        vector<int> vlevel;
        while (!qtn.empty()) {
            size = qtn.size();
            vlevel = {};
            while (size-- > 0) {
                tn = qtn.front();
                qtn.pop();
                vlevel.push_back(tn->val);

                if (tn->left) {
                    qtn.push(tn->left);
                }

                if (tn->right) {
                    qtn.push(tn->right);
                }
            }
            result.insert(result.begin(), vlevel);
        }
        return result;
    }
};
