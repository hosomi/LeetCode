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
    vector<TreeNode*> allPossibleFBT(int n) {

        if (tree.find(n) != tree.end()) {
            return tree.at(n);
        }
        
        vector<TreeNode*> result;
        if ( n==1 ) {
            TreeNode* node = new TreeNode(0);
            result.push_back(node);
            tree.insert(std::make_pair(n, result));
            return result;
        }
        
        if (n % 2 == 1) {
            for (int i = 1; i <= n - 1 - 1; i += 2) {
                int rnum = n-1-i;
                vector<TreeNode*> ltree = allPossibleFBT(i);
                vector<TreeNode*> rtree = allPossibleFBT(rnum);
                for (int j = 0; j < ltree.size(); j++) {
                    for (int k = 0; k < rtree.size(); k++) {
                        TreeNode* node = new TreeNode(0);
                        node->left = ltree[j];
                        node->right = rtree[k];
                        result.push_back(node);
                    }
                }
            }
        }

        tree.insert(std::make_pair(n, result));
        return result;
    }

private:
    map<int, vector<TreeNode*> > tree;
};
