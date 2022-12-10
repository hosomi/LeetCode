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
    int maxProduct(TreeNode* root) {
        
        totalSum(root);
        maxiPro(root);
        return (int)(max % (int)(pow(10, 9) + 7));
    }

private:
    long sum = 0;
    long max = LONG_MIN;

    void totalSum(TreeNode* node) {

        if (node == nullptr) {
            return;
        }

        sum += node->val;
        totalSum(node->left);
        totalSum(node->right);
    }

    long maxiPro(TreeNode* node) {

        if (node == nullptr) {
            return 0;
        }

        long l = maxiPro(node->left);
        long r = maxiPro(node->right);
        long sum1 = l + r + node->val;
        max = std::max(max, sum1 * (sum - sum1));
        return sum1;
    }
};
