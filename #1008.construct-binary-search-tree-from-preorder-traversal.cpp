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
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int size = preorder.size();
        if (preorder.size() == 0) {
            return NULL;
        }

        TreeNode *root;
        TreeNode *pre;
        TreeNode *cur;
        root = new TreeNode(preorder[0]);
        for (int i = 1; i < size; i++) {
            int p = preorder[i];
            cur = root;
            while (cur) {
                pre = cur;
                if (p < cur->val) {
                    cur = cur->left;
                } else if(p >= cur->val) {
                    cur = cur->right;
                }
            }

            if (p < pre->val) {
                pre->left = new TreeNode(p);
            } else if (p >= pre->val) {
                pre->right = new TreeNode(p);
            }
        }
        return root;
    }
};
