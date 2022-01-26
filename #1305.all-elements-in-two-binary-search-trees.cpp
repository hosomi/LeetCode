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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        ascending(root1);
        ascending(root2);
        std::sort(result.begin(), result.end());
        return result;
    }

private:
    vector<int> result;

    void ascending(TreeNode* root) {

        stack<TreeNode*> stk;
        TreeNode *node;
        stk.push(root);
        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
            if (!node) {
                return;
            }

            result.push_back(node->val);
            if (node->left) {
                stk.push(node->left);
            }
            if (node->right) {
                stk.push(node->right);
            }
        }
    }
};
