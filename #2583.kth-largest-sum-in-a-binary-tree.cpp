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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        priority_queue<long,vector<long>, greater<long>> pq;
        int y = 0;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            long x = 0;
            y++;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                x += node->val;
                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            pq.push(x);
        }

        if (pq.size() < k) {
            return -1;
        }

        while (pq.size() != k) {
            pq.pop();
        }
        return pq.top();
    }
};
