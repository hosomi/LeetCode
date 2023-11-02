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
    int averageOfSubtree(TreeNode* root) {

        int result = 0;
        averageOfSubtree(root, result);
        return result;
    }

private:
    pair<int,int> averageOfSubtree(TreeNode* root, int &result) {

        if (!root) {
            return { 0, 0 };
        }

        auto subtree1 = averageOfSubtree(root->left, result);
        auto subtree2 = averageOfSubtree(root->right, result);
        int avg = (root->val + subtree1.first + subtree2.first) /
            (subtree1.second + subtree2.second + 1);
        if (avg == root->val) {
            result++;
        }
        return { root->val + subtree1.first + subtree2.first, 
            subtree1.second + subtree2.second + 1 };
    }
};
