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
    TreeNode* replaceValueInTree(TreeNode* root) {

        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,nullptr});
        while (q.size()) {
            long long size = q.size();
            vector<pair<TreeNode*, TreeNode*>> arr;
            unordered_map<TreeNode*, long long> mp;
            long long sum = 0; 
            for (int i = 0; i < size; i++) {
                auto front = q.front();
                auto first = front.first;
                if (front.second != nullptr) {
                    mp[front.second] += first->val;
                }
                sum += first->val;
                arr.push_back(front);
                q.pop();
                if (first->left) {
                    q.push({first->left, first});
                }
                if (first->right) {
                    q.push({first->right, first});
                }
            }

            for (int i = 0; i < arr.size(); i++) {
                arr[i].first->val = (sum - mp[arr[i].second]);
            }

            if (size == 1) {
                arr[0].first->val = 0;
            }
        }
        return root;
    }
};
