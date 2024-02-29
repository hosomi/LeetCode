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
    bool isEvenOddTree(TreeNode* root) {

        unordered_map<int,int> last;
        return isEvenOddTree(root, last, 0);
    }

private:
    bool isEvenOddTree(TreeNode* root,
        unordered_map<int,int>& last,
        int level) {

        if (root == NULL) { 
            return true;
        }
        
        if (level % 2 == root->val % 2) {
            return false;
        }

        if (last.count(level) > 0) {
            if (level % 2 == 0 && last[level] >= root->val) {
                return false;
            }

            if (level % 2 != 0 && last[level] <= root->val) {
                return false;
            }
        }

        last[level] = root->val;
        return isEvenOddTree(root->left, last, level + 1)
            && isEvenOddTree(root->right, last, level + 1);
    }
};
