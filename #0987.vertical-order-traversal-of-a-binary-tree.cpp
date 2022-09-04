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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        this->verticalTraversal(root, 0, 0);
        vector<vector<int>> result;
        for (auto it1 = m.begin(); it1 != m.end(); ++it1) {
            vector<int> v;
            for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
                v.insert(v.end(), it2->second.begin(), it2->second.end());
            }
            result.push_back(v);
        }
        return result;
    }

private:

    map<int, map<int, multiset<int>>> m;
    void verticalTraversal(TreeNode* node, int x, int y) {

        if (node == nullptr) {
            return;
        }
        
        m[x][y].insert(node->val);
        this->verticalTraversal(node->left, x-1, y+1);
        this->verticalTraversal(node->right, x+1, y+1);
    }
};
