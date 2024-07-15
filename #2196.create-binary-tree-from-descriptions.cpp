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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int,TreeNode*> m;
        unordered_set<int> s;
        for (auto &description : descriptions) {
            if (m.find(description[0]) == m.end()) {
                m[description[0]] = new TreeNode(description[0]);
            }

            if (m.find(description[1]) == m.end()) {
                m[description[1]] = new TreeNode(description[1]);
            }

            s.insert(description[1]);
            if (description[2] == 1) {
                m[description[0]]->left = m[description[1]];
            } else {
                m[description[0]]->right = m[description[1]];
            }
        }

        int n = m.size();
        for (auto a : m) {
            if (s.find(a.first) == s.end()) {
                return a.second;
            }
        }
        return NULL ;
    }
};
