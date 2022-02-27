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
    int widthOfBinaryTree(TreeNode* root) {

        if (!root) {
            return 0;
        }
        
        int max = 0;
        queue<pair<TreeNode*,unsigned int>> q;
        q.push({root,0});
        while (!q.empty()) {
            int n=q.size();
            pair<TreeNode*,unsigned int> curr;
            unsigned int left = q.front().second;
            while (n--) {
                curr = q.front();
                q.pop();
                if (curr.first->left) {
                    q.push({curr.first->left,curr.second<<1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right,(curr.second<<1)|1});
                }
            }
            max = std::max(max,static_cast<int> (curr.second-left+1));
        }
        return max;
    }
};
