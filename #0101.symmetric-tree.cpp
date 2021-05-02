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
    bool isSymmetric(TreeNode* root) {

        std::queue<TreeNode*> qtn;
        TreeNode *tn1, *tn2;

        qtn.push(root);
        qtn.push(root);
        while (!qtn.empty()) {
            tn1 = qtn.front(); qtn.pop();
            tn2 = qtn.front(); qtn.pop();
            if (tn1 == NULL && tn2 == NULL) {
                continue;
            }

            if (tn1 == NULL || tn2 == NULL) {
                return false;
            }

            if (tn1->val != tn2->val) {
                return false;
            }

            qtn.push(tn1->left);
            qtn.push(tn2->right);
            qtn.push(tn1->right);
            qtn.push(tn2->left);
        }
        return true;
    }
};
