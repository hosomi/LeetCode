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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        treeQueries(root);
        treeQueries(root->left,rightMp[root->val], 1);
        treeQueries(root->right,leftMp[root->val], 1);

        vector<int> result;
        for (auto& q:queries) {
            result.push_back(query[q]);
        }
        return result;
    }

private:
    map<int,int> leftMp,rightMp,query;

    void treeQueries(TreeNode* root,int max,int depth) {

        if (!root) {
            return;
        }

        query[root->val] = max;
        treeQueries(root->left, std::max(max,
            depth + rightMp[root->val]), depth + 1);
        treeQueries(root->right, std::max(max,
            depth + leftMp[root->val]), depth + 1);
    }
    
    int treeQueries(TreeNode* root) {

        if (!root) {
            return 0;
        };

        int left = treeQueries(root->left);
        int right = treeQueries(root->right);
        leftMp[root->val] = left;
        rightMp[root->val] = right;
        return 1 + std::max(left, right);
    }
};
