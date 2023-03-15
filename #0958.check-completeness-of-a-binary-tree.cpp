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
    bool isCompleteTree(TreeNode* root) {
        
        vector<TreeNode*> nodes;
		nodes.push_back(root);
        int i = 0;
        while (i<nodes.size() && nodes[i]) {
            nodes.push_back(nodes[i]->left);
            nodes.push_back(nodes[i]->right);
            i++;
        }
		
        while (i <nodes.size() && !nodes[i]) {
            i++;
        }
		
        return i == nodes.size();
    }
};
