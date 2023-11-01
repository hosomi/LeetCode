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
    vector<int> findMode(TreeNode* root) {

        unordered_map<int,int> m;
        findMode(root, m);

        vector<int> results;
        int min = INT_MIN;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > min) {
                min = it->second;
                results = { it->first };
            } else if (it->second == min) {     
                results.push_back(it->first);
            }
        }
        return results;
    }

private:
    void findMode(TreeNode* root, unordered_map<int,int>&m) {

        if (!root) {
            return;
        }

        findMode(root->left, m);
        m[root->val]++;
        findMode(root->right, m);
    }
};
