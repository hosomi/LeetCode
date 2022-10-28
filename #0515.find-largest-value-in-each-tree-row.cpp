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
    vector<int> largestValues(TreeNode* root) {

        if (!root) {
            return vector<int>();
        }

        queue<TreeNode*> q;
        TreeNode* cur;
        vector<int> result;
        int counter = 0;
        int next = 0;
        int max = INT_MIN;

        q.push(root);
        counter = 1;      
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            max = std::max(max, cur->val);
            if (cur->left) {
                q.push(cur->left);
                next++;
            }

            if (cur->right) {
                q.push(cur->right);
                next++;
            }

            counter--;
            if (counter == 0) {
                result.push_back(max);
                counter = next;
                next = 0;
                max = INT_MIN;
            }
        }
        return result;
    }
};
